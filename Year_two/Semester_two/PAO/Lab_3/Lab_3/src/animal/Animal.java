package animal;

public class Animal {

    private String name;

    private int noOfLegs;

    public String getName() {
        return name;
    }

    public int getNoOfLegs() {
        return noOfLegs;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNoOfLegs(int noOfLegs) {
        this.noOfLegs = noOfLegs;
    }

    public Animal() {
    }

    public Animal(String name, int noOfLegs) {
        this.name = name;
        this.noOfLegs = noOfLegs;
    }

    public void move(){
        System.out.println("I can move!");
    }

    public void eat(){
        System.out.println("I need something to eat");
    }


    //supraincarcare metoda (overloading)

    public void eat(String whatIEat){
        System.out.println("I eat" + whatIEat);
    }


}
