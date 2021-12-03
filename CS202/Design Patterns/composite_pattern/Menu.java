package composite_pattern;

import java.util.ArrayList;

public class Menu extends MenuComponent {
    ArrayList<MenuComponent> menuComponents;

    public Menu(String name, String description) {
        this.name = name;
        this.description = description;
        menuComponents = new ArrayList<MenuComponent>();
    }

    public void add(MenuComponent menuComponent) {
        menuComponents.add(menuComponent);
    }

    public void remove(MenuComponent menuComponent) {
        menuComponents.remove(menuComponent);
    }

    public MenuComponent getChild(int index) {
        return menuComponents.get(index);
    }

    public void print() {
        System.out.println(name + " (" + description + ")");
        for (MenuComponent menuComponent : menuComponents)
            menuComponent.print();
    }
}