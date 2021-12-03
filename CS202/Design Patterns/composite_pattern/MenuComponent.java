package composite_pattern;

public abstract class MenuComponent {
    protected String name, description;

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public abstract void print();

    public void add(MenuComponent menuComponent) {
        throw new UnsupportedOperationException();
    }

    public void remove(MenuComponent menuComponent) {
        throw new UnsupportedOperationException();
    }

    public MenuComponent getChild(int index) {
        throw new UnsupportedOperationException();
    }

    public double getPrice() {
        throw new UnsupportedOperationException();
    }

    public boolean isVegetarian() {
        throw new UnsupportedOperationException();
    }
}