import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class HelloApplication extends Application
{

    @Override
        public void start(Stage primaryStage) {

        TextField nameField = new TextField();
        nameField.setPromptText("Enter Name");
        TextField idField = new TextField();
        idField.setPromptText("Enter ID");
        TextField emailField = new TextField();
        emailField.setPromptText("Enter Email");

        RadioButton maleRadioButton = new RadioButton("Male");
        RadioButton femaleRadioButton = new RadioButton("Female");
        ToggleGroup genderToggleGroup = new ToggleGroup();
        maleRadioButton.setToggleGroup(genderToggleGroup);
        femaleRadioButton.setToggleGroup(genderToggleGroup);

        CheckBox termsCheckBox = new CheckBox("I agree to the terms and conditions");


        TableView<Student> tableView = new TableView<>();
        TableColumn<Student, String> nameColumn = new TableColumn<>("Name");
        nameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
        TableColumn<Student, String> idColumn = new TableColumn<>("ID");
        idColumn.setCellValueFactory(new PropertyValueFactory<>("id"));
        TableColumn<Student, String> emailColumn = new TableColumn<>("Email");
        emailColumn.setCellValueFactory(new PropertyValueFactory<>("email"));
        TableColumn<Student, String> genderColumn = new TableColumn<>("Gender");
        genderColumn.setCellValueFactory(new PropertyValueFactory<>("gender"));
        tableView.getColumns().addAll(nameColumn, idColumn, emailColumn, genderColumn);


        Button addButton = new Button("Add Student");
        addButton.setOnAction(e -> {
            if (!nameField.getText().isEmpty() && !idField.getText().isEmpty() && !emailField.getText().isEmpty() && genderToggleGroup.getSelectedToggle() != null && termsCheckBox.isSelected()) {
                Student student = new Student(nameField.getText(), idField.getText(), emailField.getText(), ((RadioButton)genderToggleGroup.getSelectedToggle()).getText());
                tableView.getItems().add(student);
                // Clearing form fields after adding student
                nameField.clear();
                idField.clear();
                emailField.clear();
                genderToggleGroup.selectToggle(null);
                termsCheckBox.setSelected(false);
            }
            else {

                Alert alert = new Alert(Alert.AlertType.WARNING);
                alert.setTitle("Incomplete Form");
                alert.setHeaderText(null);
                alert.setContentText("Please fill in all fields and agree to the terms and conditions.");
                alert.showAndWait();
            }
        });

        VBox formLayout = new VBox(10);
        formLayout.getChildren().addAll(
            new Label("Name:"), nameField,
            new Label("ID:"), idField,
            new Label("Email:"), emailField,
            new Label("Gender:"), new HBox(10, maleRadioButton, femaleRadioButton),
            termsCheckBox,
            addButton
        );


        BorderPane root = new BorderPane();
        root.setLeft(formLayout);
        root.setBottom(tableView);

        Scene scene = new Scene(root, 600, 400);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Student Registration Form");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

    public static class Student {
        private String name;
        private String id;
        private String email;
        private String gender;

        public Student(String name, String id, String email, String gender) {
            this.name = name;
            this.id = id;
            this.email = email;
            this.gender = gender;
        }

        public String getName() {
            return name;
        }

        public String getId() {
            return id;
        }

        public String getEmail() {
            return email;
        }

        public String getGender() {
            return gender;
        }
    }
}
