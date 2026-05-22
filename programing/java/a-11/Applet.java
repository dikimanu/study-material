import java.applet.Applet;
import java.awt.*;

public class Applet extends Applet {

    Label label;
    TextField textField;
    Checkbox red, green, blue, yellow;

    public void init() {

        // Create Label
        label = new Label("Enter Text:");

        // Create TextField
        textField = new TextField(20);

        // Create Checkboxes
        red = new Checkbox("Red");
        green = new Checkbox("Green");
        blue = new Checkbox("Blue");
        yellow = new Checkbox("Yellow");

        // Add components to applet
        add(label);
        add(textField);
        add(red);
        add(green);
        add(blue);
        add(yellow);
    }
}