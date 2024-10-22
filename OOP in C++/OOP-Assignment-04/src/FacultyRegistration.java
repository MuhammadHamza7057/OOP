import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class FacultyRegistration extends JDialog{
    private JPanel FacultyRegistration;
    private JTextField tfemail;
    private JTextField tfname;
    private JPasswordField pfpassword;
    private JPasswordField pfconfirmpassword;
    private JTextField tfposition;
    private JButton btnlogin;
    private JButton btnOK;
    private String email;
    private String name;
    private String password;
    private String position;
    private int id;

    public FacultyRegistration(JFrame parent) {
        super(parent, "Faculty Registration", true);
        setSize(400, 500);
        setLocationRelativeTo(null);
        setContentPane(FacultyRegistration);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setModal(true);
        setLocationRelativeTo(parent);

        btnlogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Facultylogin facultylogin = new Facultylogin(null);
                facultylogin.setVisible(true);
                dispose();
            }
        });
        btnOK.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String email = tfemail.getText();
                String name = tfname.getText();
                String password = new String(pfpassword.getPassword());
                String confirmpassword = new String(pfconfirmpassword.getPassword());
                String position = tfposition.getText();

                if (email.isEmpty() || name.isEmpty() || password.isEmpty() || confirmpassword.isEmpty() || position.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "Please fill all fields");
                    return;
                } else if (!password.equals(confirmpassword)) {
                    JOptionPane.showMessageDialog(null, "Password does not match");
                    return;
                }

               FacultyRegistration faculty = addFacultyToDatabase(email, name, password, confirmpassword, position);
                if (faculty != null) {
                    JOptionPane.showMessageDialog(null, "Faculty added successfully");
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "Faculty not added");
                }
            }

            private FacultyRegistration addFacultyToDatabase(String email, String name, String password, String confirmpassword, String position) {
                FacultyRegistration faculty = new FacultyRegistration(null);
                faculty.email = email;
                faculty.name = name;
                faculty.password = password;
                faculty.position = position;


                try {
                   // Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/registration", "root", "");
                    Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/universitydata", "root", "Hamza123");
                    String query = "INSERT INTO facultydata (email, name, password, position) VALUES (?, ?, ?, ?)";
                    PreparedStatement preparedStatement = con.prepareStatement(query, Statement.RETURN_GENERATED_KEYS);
                    preparedStatement.setString(1, email);
                    preparedStatement.setString(2, name);
                    preparedStatement.setString(3, password);
                    preparedStatement.setString(4, position);
                    preparedStatement.executeUpdate();
                    ResultSet resultSet = preparedStatement.getGeneratedKeys();
                    if (resultSet.next()) {
                        faculty.id = resultSet.getInt(1);
                    }
                    return faculty;
                } catch (Exception e) {
                    e.printStackTrace();
                    return null;
                }
            }
        });
        //setVisible(true);
    }

    public static void main(String[] args) {
        FacultyRegistration dialog = new FacultyRegistration(null);
        dialog.pack();
        dialog.setVisible(true);

    }
}
