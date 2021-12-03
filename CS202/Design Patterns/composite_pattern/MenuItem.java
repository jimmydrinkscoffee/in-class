package composite_pattern;

public class MenuItem extends MenuComponent {
    private double price;
    private boolean vegetarian;

    public MenuItem(String name, String description, double price, boolean vegetarian) {
        this.name = name;
        this.description = description;
        this.price = price;
        this.vegetarian = vegetarian;
    }

    public double getPrice() {
        return price;
    }

    public boolean isVegetarian() {
        return vegetarian;
    }

    public void print() {
        String printedString = name;
        printedString += vegetarian ? " (v)" : "";
        printedString += " - " + price;
        printedString += " (" + description + ")";
        System.out.println(printedString);
    }
}