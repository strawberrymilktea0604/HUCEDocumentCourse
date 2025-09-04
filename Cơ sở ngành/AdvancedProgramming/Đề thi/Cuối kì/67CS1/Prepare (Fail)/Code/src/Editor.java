import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
public class Editor {



    private Shape[] elements;
    public void calculateArea() {

        

    }

    public void saveShape() throws IOException {
        for (int i = 0; i <= 1; i++) {
            if(elements[i] instanceof Square) {
                try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("square.dat"))) {
                    oos.writeObject(elements[i]);
                }
            }
        }

        for (int i = 0; i <= 1; i++) {
            if(elements[i] instanceof Circle) {
                try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("circle.dat"))) {
                    oos.writeObject(elements[i]);
                }
            }
        }

    }

    public Editor() {

    }

    public Editor(Shape[] elements) {

    }


}
