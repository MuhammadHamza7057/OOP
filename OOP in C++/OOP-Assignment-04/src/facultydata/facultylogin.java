package facultydata;

public class facultylogin {
    private int id;
    private String name;
    private String password;

    public facultylogin(int id, String name, String password) {
        this.id = id;
        this.name = name;
        this.password = password;
    }

    public facultylogin() {

    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getPassword() {
        return password;
    }
}
