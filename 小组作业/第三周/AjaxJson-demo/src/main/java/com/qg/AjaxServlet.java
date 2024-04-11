package com.qg;

import com.fasterxml.jackson.databind.ObjectMapper;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URLEncoder;
import java.sql.*;
import java.util.*;
import org.json.*;

@WebServlet(urlPatterns = "/AjaxServlet")
public class AjaxServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        //String userData = request.getParameter("data");
        response.setCharacterEncoding("utf-8");
        request.setCharacterEncoding("utf-8");

        // JDBC连接和查询
        String jdbcURL = "jdbc:mysql://localhost:3306/mysql?characterEncoding=UTF-8";
        String dbUser = "root";
        String dbPassword = "123456";

        ResultSet result = null;
        PreparedStatement pstmt = null;
        Connection conn = null;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection(jdbcURL, dbUser, dbPassword);
            // 假设我们有一个名为 users 的表，并且我们想根据 userData 查
            String sql = "SELECT * FROM tb_qg";
            pstmt = conn.prepareStatement(sql);

            result = pstmt.executeQuery();

            //Account account = null;
            HashMap<String, String> map = new HashMap<>();
            //ObjectMapper mapper = new ObjectMapper();
            JSONArray jsonArray = new JSONArray();
            JSONObject jsonObject = null;
            while (result.next()) {
                // 处理结果
                //int id = result.getInt("id");
                String name = result.getString("name");
                String sex = result.getString("sex");
                String birthday = result.getString("birthday");
                String dept = result.getString("dept");

                /*map.put("name",name);
                map.put("sex",sex);
                map.put("birthday",birthday);
                map.put("dept",dept);*/
                jsonObject = new JSONObject();
                jsonObject.put("name",name);
                jsonObject.put("sex",sex);
                jsonObject.put("birthday",birthday);
                jsonObject.put("dept",dept);
                jsonArray.put(jsonObject);
                // 发送响应到前端
                //response.getWriter().println(account);
                //response.getWriter().println(mapper.writeValueAsString(map));
            }
            response.getWriter().write(jsonArray.toString());
            result.close();
            pstmt.close();
            conn.close();
        } catch (Exception e) {
            e.printStackTrace();
            response.getWriter().println("<h1>Database error: </h1>" + e.getMessage());
        } finally {
            try {
                if (result != null) {
                    result.close();
                }
                if (pstmt != null) {
                    pstmt.close();
                }
                if (conn != null) {
                    conn.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
