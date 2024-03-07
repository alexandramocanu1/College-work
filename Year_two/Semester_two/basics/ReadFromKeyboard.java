package basics;

import java.util.HashMap;
import java.util.Scanner;

public class ReadFromKeyboard {
    private final HashMap<String, Integer> data;

    public ReadFromKeyboard() {
        this.data = new HashMap<>();
    }

    public void create(String username, int sold) {
        data.put(username, sold);
        System.out.println("User '" + username + "' with sold '" + sold + "' was created.");
    }

    public void read(String username) {
        if (data.containsKey(username)) {
            System.out.println("User '" + username + "' has sold '" + data.get(username) + "'.");
        } else {
            System.out.println("User '" + username + "' not found.");
        }
    }

    public void update(String username, int sold) {
        if (data.containsKey(username)) {
            data.put(username, sold);
            System.out.println("The sold was updated for user '" + username + "' to '" + sold + "'.");
        } else {
            System.out.println("User '" + username + "' not found.");
        }
    }

    public void delete(String username) {
        if (data.containsKey(username)) {
            data.remove(username);
            System.out.println("User '" + username + "' was deleted.");
        } else {
            System.out.println("User '" + username + "' not found.");
        }
    }

    public void help() {
        System.out.println("\nAccepted commands:");
        System.out.println("\thelp: Instructions on how to use the application");
        System.out.println("\tcreate: Create new user. Requires username and sold.");
        System.out.println("\tread: Read user data. Requires username.");
        System.out.println("\tupdate: Update user data. Requires username and new sold.");
        System.out.println("\tdelete: Delete user data. Requires username.");
        System.out.println("\tquit: Close the application.");
    }

    public void quit() {
        System.out.println("Closing the application.");
        System.exit(0);
    }

    public void executeCommand(String command) {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = command.split(" ");

        switch (tokens[0]) {
            case "help":
                help();
                break;
            case "quit":
                quit();
                break;
            case "create":
                if (tokens.length < 3) {
                    System.out.println("Invalid number of arguments for create command. Requires username and sold.");
                    break;
                }
                create(tokens[1], Integer.parseInt(tokens[2]));
                break;
            case "read":
                if (tokens.length < 2) {
                    System.out.println("Invalid number of arguments for read command. Requires username.");
                    break;
                }
                read(tokens[1]);
                break;
            case "update":
                if (tokens.length < 3) {
                    System.out.println("Invalid number of arguments for update command. Requires username and new sold.");
                    break;
                }
                update(tokens[1], Integer.parseInt(tokens[2]));
                break;
            case "delete":
                if (tokens.length < 2) {
                    System.out.println("Invalid number of arguments for delete command. Requires username.");
                    break;
                }
                delete(tokens[1]);
                break;
            default:
                System.out.println("Invalid command. Type 'help' for instructions.");
                break;
        }
    }

    public static void main(String[] args) {
        ReadFromKeyboard reader = new ReadFromKeyboard();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("Enter Command >>> ");
            String command = scanner.nextLine();
            reader.executeCommand(command);
        }
    }
}
