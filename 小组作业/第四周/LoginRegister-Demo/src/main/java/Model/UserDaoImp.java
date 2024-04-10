package Model;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

public class UserDaoImp implements UserDao {
    static DataSource datasource;
    static {
        try {
            Properties prop = new Properties();
            InputStream ips= UserDaoImp.class.getClassLoader().getResourceAsStream("jdbc.properties");
            prop.load(ips);
            //////// 获取Druid连接池对象
            datasource = DruidDataSourceFactory.createDataSource(prop);
            //////注册驱动
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static Connection getConnection() throws SQLException {
        System.out.println("数据库连接成功！！！");
        return datasource.getConnection();
    }
    @Override
    public boolean create(String username,String phonenumber,String IDcard,String password) {
        //////  实现创建用户到数据库
        PreparedStatement pstmt = null;
        try {
            //// 定义SQL语句
            String sql = "insert into tb_users(username,phonenumber,Idcard,password) values(?,?,?,?)";
            //// 创建执行对象
            pstmt = getConnection().prepareStatement(sql);
            pstmt.setString(1,username);
            pstmt.setString(2,phonenumber);
            pstmt.setString(3,IDcard);
            pstmt.setString(4,password);
            /////  根据影响行数判断操作是否成功
            int count = pstmt.executeUpdate();
            if (count > 0) {
                System.out.println("注册成功！！！");
                return true;
            } else {
                System.out.println("注册失败！！！");
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        } finally {
            try {
                if (pstmt != null) {
                    pstmt.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public boolean search(String username, String password) {
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        try {
            //// 定义SQL语句
            String sql = "select * from tb_users where username = ? and password = ?";
            //// 创建执行对象
            pstmt = getConnection().prepareStatement(sql);
            pstmt.setString(1,username);
            pstmt.setString(2,password);
            /////  根据Resultset返回内容来判断操作是否成功
            rs = pstmt.executeQuery();
            if (rs.next()) {
                System.out.println("登录成功");
                return true;
            } else {
                System.out.println("登录失败");
                return false;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        } finally {
            try {
                if (rs != null) {
                    rs.close();
                }
                if (pstmt != null) {
                    pstmt.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public String findPassword(String username,String IDcard) {
        PreparedStatement pstmt = null;
        ResultSet rs = null;
        try {
            //// 定义SQL语句
            String sql = "select * from tb_users where username = ? and Idcard = ?";
            //// 创建执行对象
            pstmt = getConnection().prepareStatement(sql);
            pstmt.setString(1,username);
            pstmt.setString(2,IDcard);
            /////  根据Resultset返回内容来判断操作是否成功
            rs = pstmt.executeQuery();
            if (rs.next()) {
                String password = rs.getString("password");
                System.out.println(password);
                return password;
            } else {
                return null;
            }
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        } finally {
            try {
                if (rs != null) {
                    rs.close();
                }
                if (pstmt != null) {
                    pstmt.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
