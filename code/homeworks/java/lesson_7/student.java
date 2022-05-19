//using Java Swing to create a form of students by zwj 19041805
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class student {
    JFrame frame;
    JPanel panel;
    JTextField collage,major,grade,name,id,age,class_;
    JButton button;
    JLabel labelcollage,labelmajor,labelgrade,labelname,labelid,labelage,labelclass;
    String input = "";
    double num1, num2, result;
    int operator;
    public static void main(String[] args){
        java.awt.EventQueue.invokeLater(student::new);
    }
    public student(){
        frame = new JFrame("学生信息调查表");
        frame.setVisible(true);
        frame.setSize(500, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new BorderLayout());
        panel = new JPanel();
        GridBagLayout layout = new GridBagLayout();
        GridBagConstraints gbc = new GridBagConstraints();
        panel.setLayout(layout);
        collage = new JTextField(30);
        gbc.ipady = 20;
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        labelcollage = new JLabel("学院");
        labelcollage.setFont(new Font("Arial", Font.BOLD, 20));
        panel.add(labelcollage, gbc);
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(collage, gbc);
        labelmajor = new JLabel("专业");
        labelmajor.setFont(new Font("Arial", Font.BOLD, 20));
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        panel.add(labelmajor, gbc);
        major = new JTextField(30);
        gbc.gridx = 1;
        gbc.gridy = 1;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(major, gbc);
        labelgrade = new JLabel("年级");
        labelgrade.setFont(new Font("Arial", Font.BOLD, 20));
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        panel.add(labelgrade, gbc);
        grade = new JTextField(30);
        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(grade, gbc);
        labelname = new JLabel("姓名");
        labelname.setFont(new Font("Arial", Font.BOLD, 20));
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        panel.add(labelname, gbc);
        name = new JTextField(30);
        gbc.gridx = 1;
        gbc.gridy = 3;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(name, gbc);
        labelid = new JLabel("学号");
        labelid.setFont(new Font("Arial", Font.BOLD, 20));
        gbc.gridx = 0;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        panel.add(labelid, gbc);
        id = new JTextField(30);
        gbc.gridx = 1;
        gbc.gridy = 4;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(id, gbc);
        labelage = new JLabel("年龄");
        labelage.setFont(new Font("Arial", Font.BOLD, 20));
        gbc.gridx = 0;
        gbc.gridy = 5;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        panel.add(labelage, gbc);
        age = new JTextField(30);
        gbc.gridx = 1;
        gbc.gridy = 5;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(age, gbc);
        labelclass = new JLabel("班级");
        labelclass.setFont(new Font("Arial", Font.BOLD, 20));
        gbc.gridx = 0;
        gbc.gridy = 6;
        gbc.gridwidth = 1;
        gbc.gridheight = 1;
        panel.add(labelclass, gbc);
        class_ = new JTextField(30);
        gbc.gridx = 1;
        gbc.gridy = 6;
        gbc.gridwidth = 5;
        gbc.gridheight = 1;
        panel.add(class_, gbc);
        button = new JButton("提交");
        gbc.gridx = 0;
        gbc.gridy = 7;
        gbc.gridwidth = 6;
        gbc.gridheight = 1;
        panel.add(button, gbc);
        frame.add(panel, BorderLayout.CENTER);
    }
}