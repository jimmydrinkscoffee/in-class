package composite_pattern;

public class MenuTestDrive {
    public static void main(String[] args) {
        MenuComponent allMenus = new Menu("Bigfather Menu", "No description");

        MenuItem menuItem1 = new MenuItem("Item 1", "Item description 1", 100, true);
        MenuItem menuItem2 = new MenuItem("Item 2", "Item description 2", 200, false);
        MenuItem menuItem3 = new MenuItem("Item 3", "Item description 3", 300, true);
        MenuItem menuItem4 = new MenuItem("Item 4", "Item description 4", 400, false);
        MenuItem menuItem5 = new MenuItem("Item 5", "Item description 5", 500, true);

        Menu menu1 = new Menu("Menu 1", "Menu description 1");
        menu1.add(menuItem1);
        menu1.add(menuItem2);
        menu1.add(menuItem3);

        Menu menu2 = new Menu("Menu 2", "Menu description 2");
        menu2.add(menu1);
        menu2.add(menuItem4);
        menu2.add(menuItem5);

        Menu menu3 = new Menu("Menu 3", "Menu description 3");
        menu3.add(menu1);
        menu3.add(menu2);

        allMenus.add(menu1);
        allMenus.add(menu2);
        allMenus.add(menu3);

        allMenus.print();
    }
}