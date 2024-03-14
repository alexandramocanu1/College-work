package animal.bird;

import java.util.Objects;

public class Duck extends Bird {

    private int length;

    public Duck(int noOfLegs, String name, String colour, int lenght){
        super(noOfLegs, name, colour);
        this.length = lenght;
    }

    @Override
    public void move(){
        System.out.println("I can swim!");
    }

    @Override
    public void sing(){
        System.out.println("I can quack!");
    }

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        this.length = length;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;

        Duck duck = (Duck) obj;

        return super.equals(obj) && this.length == duck.length;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), length);
    }

}

