package Maze;

    public class Position{
        private int x;
        private int y;

        Position() {
            this(0, 0);
        }

        Position (int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int getx(){
            return x;
        }

        public int gety(){
            return y;
        }

        public void setx(int a) {
            x = a;
        }

        public void sety(int a) {
            y = a;
        }
    }
