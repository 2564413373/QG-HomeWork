package Controller;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.Method;

public class BaseServlet extends HttpServlet {
    @Override/*
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ///////// 获取请求体参数
        String MethodName = request.getParameter("method");
        ///////  获得指定方法并执行
        try {
            Class<? extends BaseServlet> actionclass = this.getClass();
            Method method = actionclass.getMethod(MethodName,HttpServletRequest.class,HttpServletResponse.class);
            method.invoke(this,request,response);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }*/
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
       doPost(request,response);
    }

    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        try {
            // 获取请求标识
            String MethodName = request.getParameter("method");
            // 获取指定类的字节码对象
            Class<? extends BaseServlet> clazz = this.getClass();//这里的this指的是继承BaseServlet对象
            // 通过类的字节码对象获取方法的字节码对象
            Method method = clazz.getMethod(MethodName, HttpServletRequest.class, HttpServletResponse.class);
            // 让方法执行
            method.invoke(this, request, response);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
