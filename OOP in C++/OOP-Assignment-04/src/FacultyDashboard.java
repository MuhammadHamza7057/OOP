import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FacultyDashboard extends JDialog{
    private JComboBox<String> cbchoice;
    private JPanel FacultyDashboard;

    public FacultyDashboard(JFrame parent) {
        super(parent, "Faculty Dashboard", true);
        setSize(300, 400);
        setLocationRelativeTo(null);
        setContentPane(FacultyDashboard);
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setModal(true);
        setLocationRelativeTo(parent);
        //ComboBox Code
        cbchoice.addItem("Select Choice");
        cbchoice.addItem("Genarte Time Table");
        cbchoice.addItem("Search Time Table Teacher Wise");
        cbchoice.addItem("Search Room Wise");
        cbchoice.addItem("Search Course Wise");
        cbchoice.addItem("Search Section Wise");
        cbchoice.addItem("Search Day Wise");
        cbchoice.addItem("Add Course");
        cbchoice.addItem("Remove Course");
        cbchoice.addItem("Add MakeUp Class");







        cbchoice.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("FacultyDashboard");
        frame.setContentPane(new FacultyDashboard(null).FacultyDashboard);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setVisible(true);
    }


}
