package Json;

import com.alibaba.fastjson.JSON;

public class JsonDemo {
    public static void main(String[]args) {
        User user = new User();
        user.setUsername("qgstudio");
        user.setPassword("qgstudio");
        //////  将Java对象转化成JSON字符串
        String jsonstring = JSON.toJSONString(user);
        System.out.println(jsonstring);

        //////  将JSON字符串转换成Java对象
        User user1 = JSON.parseObject("{\"password\":\"qgstudio\",\"username\":\"qgstudio\"}", User.class);
        System.out.println(user1);
    }
}
