package com.qg;

import java.io.FileInputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.Scanner;
import javax.sql.DataSource;
import com.alibaba.druid.pool.DruidDataSourceFactory;
import org.junit.*;

public class AccountTest {
	 ////////配置文件以及驱动
	 //static Connection conn = null;
	 static DataSource datasource;
	 static {
		 try {
			 Properties prop = new Properties();
			 prop.load(new FileInputStream("../第一周/src/com/qg/jdbc.properties"));
			 //////// 获取Druid连接池对象
			 datasource = DruidDataSourceFactory.createDataSource(prop);
			 //////注册驱动
			 Class.forName("com.mysql.cj.jdbc.Driver");
		 } catch (Exception e) {
			 e.printStackTrace();
		 }
	 }
	 ///////// 连接数据库操作
	 public static Connection getConnection() throws SQLException {
		 System.out.println("Database connnection successful！");
		 return datasource.getConnection();
	 }
	  //////// 关闭资源操作
	 public static void close(PreparedStatement pstmt,Connection conn) {
		 if(pstmt != null){
        try {
            pstmt.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    if(conn != null){
        try {
            conn.close();//归还连接
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
 ////////////  查找所有： 结果返回 Account对象的集合
	 //@Test
    public void ReadAll() throws Exception{
   	 ///// 定义sql
   	 String sql = "select * from tb_qg";
   	 ///// 获取 pstmt 对象
   	 PreparedStatement pstmt = getConnection().prepareStatement(sql);
   	 ResultSet rs = pstmt.executeQuery();
   	 ////// 封装Account对象
   	 List<Account> list = new ArrayList<>();
   	 Account account = null;
   	 while (rs.next()) {
   		 int id = rs.getInt("id");
   		 String name = rs.getString("name");
   		 String sex = rs.getString("sex");
   		 String birthday = rs.getString("birthday");
   		 String dept = rs.getString("dept");
   		 
   		 account = new Account();
   		 account.setId(id);
   		 account.setName(name);
   		 account.setSex(sex);
   		 account.setBirthday(birthday);
   		 account.setDept(dept);
   		 /////// 装载集合
   		 list.add(account);
   	 }
   	 System.out.println(list);
   	 close(pstmt,null);
    }
	 ////@Test
	 ////////  添加操作
	 public void Add() throws SQLException { ////// id设置为自增，所以不用自己添加
		 Scanner sc = new Scanner(System.in);
		 String sql = "insert into tb_qg(name,sex,birthday,dept) values(?,?,?,?)";
		 PreparedStatement pstmt = getConnection().prepareStatement(sql);
		 //////// 设置参数
		 String add_Name = sc.next();
		 String add_Sex = sc.next();
		 String add_Birthday = sc.next();
		 String add_Dept = sc.next();
		 pstmt.setString(1, add_Name);
		 pstmt.setString(2, add_Sex);
		 pstmt.setString(3, add_Birthday);
		 pstmt.setString(4, add_Dept);
		 
		/////// 受影响的行数
		 int count = pstmt.executeUpdate();
		 if (count > 0) {
			 System.out.println("Add succeeds");
		 } else {
			 System.out.println("Add fails");
		 }
		 close(pstmt,null);
	 }
	 ////@Test
	 /////// 删除操作(可以根据你输入的id从而删除指定数据)
    public void Delete() throws SQLException {
   	 int id;
   	 Scanner sc = new Scanner(System.in);
   	 id = sc.nextInt();
   	 String sql = "delete from tb_qg where id = ?";
   	 PreparedStatement pstmt = getConnection().prepareStatement(sql);
   	 pstmt.setInt(1, id);
   	 int count = pstmt.executeUpdate();
   	 if (count > 0) {
   		 System.out.println("Operation succeeds");
   	 } else {
   		 System.out.println("Operation fails");
   	 }
   	 close(pstmt,null);
    }
    //@Test
	 ////////// 更改操作 ,能改任意属性（除id）的值;
	 public void Update() throws SQLException {
		 Scanner sc = new Scanner(System.in);
		 String sql = "update tb_qg set name = ? ,sex = ?,birthday = ?,dept = ? where id = ?";
		 PreparedStatement pstmt = getConnection().prepareStatement(sql);
		 /////// 通过序号选择你要改的列
		 System.out.println("Input the new value you expect（1.name 2.sex 3.birthday 4.dept 5.id）");
		 String new_Name = sc.next();
		 String new_Sex = sc.next();
		 String new_Birthday = sc.next();
		 String new_Dept = sc.next();
		 int id = sc.nextInt();
		 pstmt.setString(1, new_Name);
		 pstmt.setString(2, new_Sex);
		 pstmt.setString(3, new_Birthday);
		 pstmt.setString(4, new_Dept);
		 pstmt.setInt(5, id);
		 int count = pstmt.executeUpdate();
   	 if (count > 0) {
   		 System.out.println("Operation succeeds");
   	 } else {
   		 System.out.println("Operation fails");
   	 }
		 close(pstmt,null);
	 }
    
    //////////////// 主函数
    public static void main(String []args) {
   	 try {
   	 int choice = 0;
   	 Scanner sc = new Scanner(System.in);
   	 AccountTest at = new AccountTest();
   	 boolean loop = true;
   	 ////// 1. 查询 2.添加 3.删除 4.更改 其余数字：退出
   	 System.out.println("Program begin,please input your choice of four operations.");
   	 while (loop) {
   		 choice = sc.nextInt();
   		 switch (choice) {
   		 case 1:
   			 at.ReadAll();
   			 break;
   		 case 2:
   			 at.Add();
   			 break;
   		 case 3:
   			 at.Delete();
   			 break;
   		 case 4:
   			 at.Update();
   			 break;
   		 default:
   			 System.out.println("Operation unvalid");
   			 loop = false;
   			 break;
   		 }
   	   }
   	 } catch (Exception e) {
   		 e.printStackTrace();
   	 }
    }
}
