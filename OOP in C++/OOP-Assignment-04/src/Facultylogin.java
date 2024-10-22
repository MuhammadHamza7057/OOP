import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class Facultylogin extends JDialog{
    private JPasswordField pfpassword;
    private JTextField tfemail;
    private JPanel Facultylogin;
    private JButton btnback;
    private JButton btnlogin;
    private JPanel FacultyRegistration;
    private JPanel FacultyDashboard;

    public Facultylogin(JFrame parent) {
        super(parent, "Faculty Login", true);
        setSize(300, 400);
        setLocationRelativeTo(null);
        setContentPane(Facultylogin);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setModal(true);
        setLocationRelativeTo(parent);

        btnback.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                FacultyRegistration facultyRegistration = new FacultyRegistration(null);
                Facultylogin.setVisible(true);
                facultyRegistration.setVisible(true);
            }
        });
        btnlogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String email = tfemail.getText();
                String password = new String(pfpassword.getPassword());

                if (email.isEmpty() || password.isEmpty()) {
                    JOptionPane.showMessageDialog(null, "Please fill all fields");
                    return;
                } /*else {
                    if (name.equals("Amar@gmail.com") && password.equals("123")) {
                        JOptionPane.showMessageDialog(null, "Login Successful");
                        dispose();
                    } else {
                        JOptionPane.showMessageDialog(null, "Login Failed");
                    }
                }*/

                user = getAuthenticateduser(email, password);
                /*if (user != null) {
                    //JOptionPane.showMessageDialog(null, "Login Successful");
                    dispose();
                } else {
                    JOptionPane.showMessageDialog(null, "Login Failed");
                }*/
            }

            public Object user;
            private <User> User getAuthenticateduser(String email, String password) {
                User user = null;
               final String DB_URL = "jdbc:mysql://localhost:3306/universitydata";
                final String USER = "root";
                final String PASS = "Hamza123";

                try{

                    Connection con = DriverManager.getConnection(DB_URL, USER, PASS);
                    Statement stmt = con.createStatement();
                    String sql = "SELECT * FROM facultydata WHERE email = ? AND password = ?";
                    PreparedStatement ps = con.prepareStatement(sql);
                    ps.setString(1, email);
                    ps.setString(2, password);


                    ResultSet rs = ps.executeQuery();
                   if (rs. next()){
                       JOptionPane.showMessageDialog(null, "Login Successful");
                   }
                     else {
                       JOptionPane.showMessageDialog(null, "Login Failed");
                   }
                }
                catch (Exception e){
                    e.printStackTrace();
                }

                return user;


            }


        });

        btnlogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                FacultyDashboard facultyDashboard = new FacultyDashboard(null);
                facultyDashboard.setVisible(true);
                dispose();
            }
        });
        btnlogin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                FacultyDashboard facultyDashboard = new FacultyDashboard(null);
                facultyDashboard.setVisible(true);
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        Facultylogin dialog = new Facultylogin(null);
        dialog.pack();
        dialog.setVisible(true);
    }
}
