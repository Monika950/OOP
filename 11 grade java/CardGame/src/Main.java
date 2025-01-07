import org.elsys.cardgame.api.*;

import java.util.*;

import static org.elsys.cardgame.api.Rank.getRank;
import static org.elsys.cardgame.api.Suit.getSuit;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Card> cards = new ArrayList<>();

        String input = scanner.nextLine();
        String[] cardStrings = input.split(" ");

        for (String cardString : cardStrings) {
            char suitChar = cardString.charAt(0);
            String rankString = cardString.substring(1);

            Suit suit = getSuit(suitChar);
            Rank rank = getRank(rankString);

            if (suit != null && rank != null) {
                cards.add(new CardImpl(rank, suit));
            } else {
                System.out.println("ERROR: Invalid card format.");
                return;
            }
        }

        Deck currentDeck = null;
        Game game = null;

        while (true) {
            String operation = scanner.nextLine().trim();

            if (operation.equals("quit")) {
                break;
            }

            try {
                if (operation.equals("War")) {
                    if (cards.size() >= 26) {
                        currentDeck = DeckFactory.createWarDeck();
                        game = GameFactory.createGame(currentDeck, getOperations());
                    } else {
                        System.out.println("ERROR: Not enough cards for War");
                    }
                } else if (operation.equals("Belote")) {
                    if (cards.size() >= 32) {
                        currentDeck = DeckFactory.createBeloteDeck();
                        game = GameFactory.createGame(currentDeck, getOperations());
                    } else {
                        System.out.println("ERROR: Not enough cards for Belote");
                    }
                } else if (operation.equals("Santase")) {
                    if (cards.size() >= 24) {
                        currentDeck = DeckFactory.createSantaseDeck();
                        game = GameFactory.createGame(currentDeck, getOperations());
                    } else {
                        assert currentDeck != null;
                        System.out.println(currentDeck.size());
                        System.out.println("ERROR: Not enough cards for Santase");
                    }
                } else if (currentDeck == null) {
                    System.out.println("ERROR: No deck");
                }

                else if (operation.equals("deal")) {
                    if (currentDeck.size() < currentDeck.handSize()) {
                        System.out.println("ERROR: Not enough cards in deck");
                    } else {
                        List<Card> hand = currentDeck.deal();
                        System.out.println(hand);
                    }
                } else if (operation.equals("draw_top_card")) {
                    if (currentDeck.size() < 1) {
                        System.out.println("ERROR: Not enough cards in deck");
                    } else {
                        Card topCard = currentDeck.drawTopCard();
                        System.out.println(topCard);
                    }
                } else if (operation.equals("top_card")) {
                    if (currentDeck.size() < 1) {
                        System.out.println("ERROR: Not enough cards in deck");
                    } else {
                        Card topCard = currentDeck.getCards().get(0);
                        System.out.println(topCard);
                    }
                } else {
                    System.out.println("ERROR: Unknown operation");
                }
            } catch (Exception e) {
                System.out.println("ERROR: " + e.getMessage());
            }
        }

        scanner.close();
    }

    private static List<Operation> getOperations() {
        List<Operation> operations = new ArrayList<>();
        operations.add(new OperationImpl("deal") {
            @Override
            public void execute() {
            }
        });
        operations.add(new OperationImpl("draw_top_card") {
            @Override
            public void execute() {
            }
        });
        operations.add(new OperationImpl("top_card") {
            @Override
            public void execute() {
            }
        });
        return operations;
    } //  :( nqma vreme veche
}
