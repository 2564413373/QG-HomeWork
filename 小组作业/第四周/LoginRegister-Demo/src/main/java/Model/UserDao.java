package Model;

public interface UserDao {
    ///// 注册
    public boolean create(String username,String phonenumber,String IDcard,String password);

    ///// 登录
    public boolean search(String username,String password);

    ///// 找回密码
    public String findPassword(String username,String IDcard);
}
