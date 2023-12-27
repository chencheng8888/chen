package main

import (
	"database/sql"
	"fmt"
	"github.com/gin-contrib/sessions"
	"github.com/gin-contrib/sessions/cookie"
	"github.com/gin-gonic/gin"
	_ "github.com/go-sql-driver/mysql"
	"log"
	"math/rand"
	"net/http"
	"strconv"
	"time"
)

type User struct {
	ID       string `json:"ID"`
	Email    string `json:"email"`
	Username string `json:"Username"`
	Password string `json:"password"`
}
type Book struct {
	ID         int    `json:"ID"`
	Bookname   string `json:"bookname"`
	Author     string `json:"author"`
	Borrow     bool   `json:"borrow"`
	BorrowDate string `json:"borrowdate"`
	Borrower   string `json:"borrower"`
}

func main() {
	//连接mysql数据库
	db, err := sql.Open("mysql", "root:chencheng1028@tcp(127.0.0.1:3306)/bookmanagement")
	if err != nil {
		fmt.Println("error:", err)
		return
	}
	db.SetConnMaxLifetime(100)
	db.SetMaxIdleConns(10)
	if err := db.Ping(); err != nil {
		fmt.Println("connect database error")
		return
	}

	r := gin.Default() //设置一个路由
	store := cookie.NewStore([]byte("secret"))
	r.Use(sessions.Sessions("mysession", store))
	r.LoadHTMLFiles("HOME/index.html", "main_home/home.html")
	r.Static("/static", "./HOME/static")
	r.Static("/static_main", "./main_home/static_main")
	//主页重定向
	r.GET("/", func(c *gin.Context) {
		c.Redirect(http.StatusOK, "/index")
	})

	//显示主页
	r.GET("/index", func(c *gin.Context) {
		c.HTML(http.StatusOK, "index.html", gin.H{"Error": "", "Error1": ""})
	})

	//处理登录或者注册的表单
	r.POST("/index", func(c *gin.Context) {
		action := c.PostForm("action")
		processformdata(c, db, action)
	})

	//显示管理主页
	r.GET("/home", func(c *gin.Context) {
		homehinder(c, db)
	})

	//处理借书
	r.GET("/home/borrow", func(c *gin.Context) {
		borrow_hinder(c, db)
	})
	//处理用户界面
	r.Run(":8080") //启动服务器

}
func processformdata(c *gin.Context, db *sql.DB, action string) {
	switch action {
	case "login":
		login(c, db)
	case "register":
		register(c, db)
	}
}
func login(c *gin.Context, db *sql.DB) {
	fmt.Println("this is a login")
	email := c.PostForm("l-email")
	password := c.PostForm("l-password")
	fmt.Println(email, password)
	findsql := fmt.Sprintf("select * from `User` where `email` = ?")
	rows, err := db.Query(findsql, email)
	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()
	if rows.Next() {
		var sql_password string
		sqlstring := fmt.Sprintf("select `password` from `User` where `email` = '%s'", email)
		row := db.QueryRow(sqlstring)
		err := row.Scan(&sql_password)
		if err != nil {
			fmt.Println("row.Scan error ", err)
			c.HTML(http.StatusOK, "index.html", gin.H{"Error": "", "Error1": ""})
		}
		if sql_password == password {
			// 用户登录成功，保存登录状态到Session
			session := sessions.Default(c)
			session.Set("user", email)
			session.Save()
			fmt.Println("邮箱为", email, "的用户成功登录")
			c.Redirect(http.StatusFound, "/home")
		} else {
			fmt.Println("密码错误")
			c.HTML(http.StatusOK, "index.html", gin.H{"Error": "密码错误", "Error1": ""})
		}
	} else {
		fmt.Println("this is a login_9")
		fmt.Println("没找到", email)
		c.HTML(http.StatusOK, "index.html", gin.H{"Error": "未找到该邮箱", "Error1": ""})
	}

}
func register(c *gin.Context, db *sql.DB) {
	username := c.PostForm("username")
	email := c.PostForm("r-email")
	password := c.PostForm("r-password")

	findsql := fmt.Sprintf("select * from `User` where `email` = '%s'", email)
	rows, err := db.Query(findsql)
	if err != nil {
		log.Fatal(err)
	}
	defer rows.Close()
	if rows.Next() {
		fmt.Println("已经有这个邮箱了:", email)
		c.HTML(http.StatusOK, "index.html", gin.H{"Error": "", "Error1": "该邮箱已存在"})
	} else {
		id := generateNumericID(10)
		user := User{
			ID:       id,
			Email:    email,
			Username: username,
			Password: password,
		}
		insertSQL := "INSERT INTO `User` (`ID`, `Username`, `email`, `password`) VALUES (?, ?, ?, ?)"
		_, err := db.Exec(insertSQL, user.ID, user.Username, user.Email, user.Password)
		if err != nil {
			fmt.Println(err)
			fmt.Println("插入数据错误")
			c.HTML(http.StatusOK, "index.html", gin.H{"Error": "", "Error1": ""})
		}
		c.HTML(http.StatusOK, "index.html", gin.H{"Error": "", "Error1": ""})
	}
}
func homehinder(c *gin.Context, db *sql.DB) {
	// 获取Session对象
	session := sessions.Default(c)

	// 从Session中获取用户的邮箱
	userEmail := session.Get("user")

	// 检查用户是否已登录
	if userEmail == nil {
		// 用户未登录，可以执行相应的处理，例如重定向到登录页面
		c.Redirect(http.StatusFound, "/index")
		return
	}
	//获取借书人的ID
	var user_id, user_name string
	findstring := "select (`ID`,`Username`) from `User` where `email`=?"
	row := db.QueryRow(findstring, userEmail)
	err := row.Scan(&user_id, &user_name)
	if err != nil {
		fmt.Println("borrow_hinder : row.Scan err :", err)
		c.Redirect(http.StatusFound, "/home")
	}

	books := getbooks(db)
	for _, book := range books {
		fmt.Println(book)
	}
	c.HTML(http.StatusOK, "home.html", gin.H{
		"Books":    books,
		"userid":   user_id,
		"username": user_name,
	})

}
func generateNumericID(length int) string {
	rand.Seed(time.Now().UnixNano())

	// 生成一个由数字组成的字符串
	var result string
	for i := 0; i < length; i++ {
		result += fmt.Sprintf("%d", rand.Intn(10))
	}

	return result
}
func getbooks(db *sql.DB) []Book {
	books := make([]Book, 0)
	searchstring := "select * from `Book` limit 50"

	rows, err := db.Query(searchstring)
	if err != nil {
		fmt.Println("执行select * from `Book` limit 50 命令失败")
		return nil
	}
	defer rows.Close()
	for rows.Next() {
		var book Book
		rows.Scan(&book.ID, &book.Bookname, &book.Author, &book.Borrower)
		searchstring1 := "select `borrow_date` from `borrow_note` where  `borrow_book_id` = ?"
		rows1, err := db.Query(searchstring1, book.ID)
		defer rows1.Close()
		if err != nil {
			fmt.Println("执行select `borrow_date` from `borrow_note` where  `borrow_book_id` = ? 命令错误")
			return nil
		}
		if rows1.Next() {
			book.Borrow = true
			rows1.Scan(&book.BorrowDate)
		} else {
			book.Borrow = false
		}
		fmt.Println(book)
		books = append(books, book)
	}
	return books

}
func borrow_hinder(c *gin.Context, db *sql.DB) {
	// 获取Session对象
	session := sessions.Default(c)

	// 从Session中获取用户的邮箱
	userEmail := session.Get("user")

	// 检查用户是否已登录
	if userEmail == nil {
		// 用户未登录，可以执行相应的处理，例如重定向到登录页面
		c.Redirect(http.StatusFound, "/index")
		return
	}
	//获取书籍的ID
	bookIDstring := c.Query("bookID")
	//将字符串转化为整数
	bookID, err := strconv.Atoi(bookIDstring)
	if err != nil {
		fmt.Println("转化错误")
		c.Redirect(http.StatusFound, "/home")
	}

	//获取借书人的ID
	var borrower_id string
	findstring := "select `ID` from `User` where `email`=?"
	row := db.QueryRow(findstring, userEmail)
	err = row.Scan(&borrower_id)
	if err != nil {
		fmt.Println("borrow_hinder : row.Scan err :", err)
		c.Redirect(http.StatusFound, "/home")
	}

	//获取日期
	currentTime := time.Now()
	year, month, day := currentTime.Date()
	borrow_date := fmt.Sprintf("%d-%d-%d", year, month, day)
	//插入数据
	sqlstring1 := "insert into `borrow_note` (`borrow_date`, `borrow_book_id`,`borrower_id`) values (?,?,?)"
	_, err = db.Exec(sqlstring1, borrow_date, bookID, borrower_id)
	if err != nil {
		fmt.Println("borrow_hinder : db.Exec err :", err)
		c.Redirect(http.StatusFound, "/home")
	}

	sqlstring2 := "update `Book` set `borrower_id` = ? where `book_id` = ?"
	_, err = db.Exec(sqlstring2, borrower_id, bookID)
	if err != nil {
		fmt.Println("borrow_hinder : db.Exec err :", err)
		c.Redirect(http.StatusFound, "/home")
	}

	c.Redirect(http.StatusFound, "/home")
}
