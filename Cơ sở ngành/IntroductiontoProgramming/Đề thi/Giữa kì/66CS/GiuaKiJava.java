package cs1;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class GiuaKiJava {
    public static void main(String[] args)
    {
        Frame f = new Frame(200, 200, "Sample Frame");
        f.display();
        f.save();
    }
}

class Rectangle {
    private double len;
    private double wid;
    Rectangle(double l, double w) {
        this.len = l;
        this.wid = w;
    }
    Rectangle()
    {
        this(0, 0);
    }
    void display()
    {
        System.out.println("Length: " + len + " Width: " + wid);
    }
    double getLen() {
        return len;
    }
    double getWid() {
        return wid;
    }
    void setLen(double l) {
        this.len = l;
    }
    void setWid(double w) {
        this.wid = w;
    }
}

class Frame {
    private Rectangle rec;
    private String title;
    Frame()
    {
        this.rec = new Rectangle();
        this.title = "";
    }
    Frame(int l, int w, String title)
    {
        this.rec = new Rectangle(l, w);
        this.title = title;
    }
    void display()
    {
        System.out.println("Title: " + title);
        rec.display();
    }
    void save()
    {
        try {
            File fl = new File("rectangle_info.txt");
            if (fl.createNewFile())
                System.out.println("File created");
            else
            {
                System.out.println("File already exists. Overwriting...");
                if (fl.delete())
                    save();
                else
                    throw new IOException();
            }
            FileWriter fw = new FileWriter(fl);
            fw.write("Title: " + title + "\n");
            fw.write("Length: " + rec.getLen() + "\n");
            fw.write("Width: " + rec.getWid() + "\n");
            fw.close();
            System.out.println("File saved");
        }
        catch (IOException e) {
               // create a new file with that name
            System.out.println("Failed to create file");
        }
    }
}