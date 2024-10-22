import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Maindashboard extends JDialog {
    private JButton btnfacultymember;
    private JButton btnstudent;
    private JPanel Maindashboard;
    private JPanel FacultyRegistration;

    public Maindashboard(JFrame parent) {
        super(parent, "Main Dashboard", true);
        setSize(300, 600);
        setLocationRelativeTo(null);
        setContentPane(Maindashboard);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setModal(true);
        setLocationRelativeTo(parent);
        //cbchoice.additem("1");


        btnfacultymember.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {


            }
        });


        btnstudent.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
        btnfacultymember.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                FacultyRegistration facultyRegistration = new FacultyRegistration(null);
                facultyRegistration.setVisible(true);
            }
        });
    }


    public static void main(String[] args) {
        Maindashboard dialog = new Maindashboard(null);
        dialog.pack();
        dialog.setVisible(true);


    }
}
