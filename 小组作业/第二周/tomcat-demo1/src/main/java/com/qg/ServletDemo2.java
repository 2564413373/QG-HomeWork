package com.qg;

import Json.User;
import com.alibaba.fastjson.JSON;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
/**
 * urlPattern:
 * 1. 精确匹配: 输入什么网址，就要以同样的网址访问，比如/user/select，因为其精确，它被访问的优先级更高
 *
 * 2. 目录匹配： 比如 /user/*
 *
 * 3. 扩展名匹配： 比如 "*.do"  *号前面不能加斜杠
 *
 * 4. 任意匹配： 比如 "/" 和 "/*" , 后者优先级比前者高
 */
@WebServlet("/myword.moity-soeoe.xyz/login")
public class ServletDemo2 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
         resp.getWriter().println("<h1> Get request received!!! </h1>");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        ///////////    获取post请求体： 请求参数
        StringBuffer url = req.getRequestURL();
        System.out.println("URL     "+url);
        String method = req.getMethod();
        System.out.println("请求方法   "+method);
        String contenttype = req.getContentType();
        System.out.println("请求类型  "+contenttype);
        //// 1. 获取字符输入流
        BufferedReader br = req.getReader();
        //// 2. 读取数据
        String line = br.readLine();
        //User user = new User();
        //String line = JSON.toJSONString(user);
        //user.setUsername("qgstudio");
        //user.setPassword("qgstudio");
        //req.setAttribute("application/json",user);
        System.out.println("请求参数   "+line);
        resp.getWriter().println("<h1> Post request received!!! </h1>");
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.getWriter().println("<h1> Delete request received!!! </h1>");
    }

    @Override
    protected void doHead(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.getWriter().println("<h1> Head request received!!! </h1>");
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.getWriter().println("<h1> Put request received!!! </h1>");
    }

    @Override
    protected void doOptions(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.getWriter().println("<h1> Options request received!!! </h1>");
    }

    @Override
    protected void doTrace(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        System.out.println("trace........");
    }
}
