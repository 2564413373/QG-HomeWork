package qg;

public class Account {

////////////设置数据库要查询的表的变量
private int id;
private String name;
private String sex;
private String birthday;
private String dept;
public int getId() {
return id;
}
  public void setId(int id) {
       this.id = id;
}
  public String getName() {
       return name;
}
public void setName(String name) {
       this.name = name;
}
public String getSex() {
       return sex;
}
public void setSex(String sex) {
       this.sex = sex;
}
public String getBirthday() {
       return birthday;
}
public void setBirthday(String birthday) {
      this.birthday = birthday;
}
public String getDept() {
      return dept;
}
public void setDept(String dept) {
      this.dept = dept;
}
@Override
public String toString() {
      return "Account [id=" + id + ", name=" + name + ", sex=" + sex + ", birthday=" + birthday + ", dept=" + dept
		+ "]";
}
}



