import javax.swing.JFrame;

public class FaceViewer {
    public void main(String[] args){
        JFrame frame = new JFrame();
        frame.setSize(300, 400);
        frame.setTitle("An Alien Face");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // CANNOT CALL THIS DUE TO THE FOLDER NAME 10... WTF...
        FaceComponent component = new FaceComponent();
        frame.add(component);

        frame.setVisible(true);
    }
}