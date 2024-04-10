package Controller;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Model.*;
import org.json.JSONObject;

import java.io.IOException;
import java.net.http.HttpRequest;

@WebServlet(urlPatterns = "/User")
public class UserServlet extends BaseServlet {
      //////  创建Dao包对象
      private UserDaoImp udi = new UserDaoImp();
      ///////  登录函数
      public void login(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
            //////  获取请求参数
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            response.setContentType("application/json");
            ////// 调用查找函数
            boolean success = udi.search(username,password);
            if (success) {
                  JSONObject json = new JSONObject();
                  json.put("message", "登陆成功！！！");
                  response.getWriter().write(json.toString());
                  //////  如果成功就跳转页面
                  //response.sendRedirect(request.getContextPath() + "index.jsp");
            } else {
                  JSONObject json = new JSONObject();
                  json.put("message", "无此账号，登陆失败！！！");
                  response.getWriter().write(json.toString());
            }
      }

      public void register(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
            //////  获取请求参数
            String username = request.getParameter("username");
            String phonenumber = request.getParameter("phonenumber");
            String IDcard = request.getParameter("IDcard");
            String password = request.getParameter("password");
            response.setContentType("application/json");
            ////// 调用查找函数
            boolean success = udi.create(username,phonenumber,IDcard,password);
            if (success) {
                  JSONObject json = new JSONObject();
                  json.put("message", "注册成功！！！");
                  response.getWriter().write(json.toString());
            } else {
                  JSONObject json = new JSONObject();
                  json.put("message", "注册失败！！！");
                  response.getWriter().write(json.toString());
            }
      }

      public void findPassword(HttpServletRequest request,HttpServletResponse response) throws IOException {
            ///////  获取请求参数
            String username = request.getParameter("username");
            String IDcard = request.getParameter("IDcard");
            response.setContentType("application/json");
            String success = udi.findPassword(username,IDcard);
            if (success != null) {
                  JSONObject json = new JSONObject();
                  json.put("message",success);
                  response.getWriter().write(json.toString());
            }
      }
}
