package magicthegathering.impl;

import magicthegathering.game.Card;
import magicthegathering.game.CreatureCard;
import magicthegathering.game.LandCard;
import magicthegathering.game.Player;
import magicthegathering.game.ManaType;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * class implementing player
 *
 * @author Marek Vagunda
 */
public class PlayerImpl implements Player {
    private String name;
    private int lives;
    private List<Card> hand;
    private List<Card> table;

    /**
     * constuctor
     *
     * @param name player name
     */
    public PlayerImpl(String name) {
        if (name == null || name == "") {
            throw new IllegalArgumentException("invalid name");
        }
        this.name = name;
        lives = INIT_LIVES;
        hand = new ArrayList<>(Collections.emptyList());
        table = new ArrayList<>(Collections.emptyList());
    }

    /**
     * filters land cards
     *
     * @param cards mix of cards
     * @return land cards only
     */
    private List<LandCard> filterLand(List<Card> cards) {
        List<LandCard> out = new ArrayList<>();
        if (cards == null) {
            return out;
        }
        for (Card c : cards) {
            if (c instanceof LandCard) {
                out.add((LandCard) c);
            }
        }
        return out;
    }

    /**
     * filters creature cards
     *
     * @param cards mix of cards
     * @return creature cards only
     */
    private List<CreatureCard> filterCreatures(List<Card> cards) {
        List<CreatureCard> out = new ArrayList<>();
        if (cards == null) {
            return out;
        }
        for (Card c : cards) {
            if (c instanceof CreatureCard) {
                out.add((CreatureCard) c);
            }
        }
        return out;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public int getLife() {
        return lives;
    }

    @Override
    public void subtractLives(int lives) {
        this.lives -= lives;
    }

    @Override
    public boolean isDead() {
        return (lives < 1);
    }

    @Override
    public void initCards(List<Card> cards) {
        hand = new ArrayList<>(cards);
    }

    @Override
    public List<Card> getCardsInHand() {
        return hand;
    }

    @Override
    public List<Card> getCardsOnTable() {
        return table;
    }

    @Override
    public List<LandCard> getLandsOnTable() {
        return filterLand(table);
    }

    @Override
    public List<CreatureCard> getCreaturesOnTable() {
        return filterCreatures(table);
    }

    @Override
    public List<LandCard> getLandsInHand() {
        return filterLand(hand);
    }

    @Override
    public List<CreatureCard> getCreaturesInHand() {
        return filterCreatures(hand);
    }

    @Override
    public void untapAllCards() {
        for (Card c : table) {
            c.untap();
        }
    }

    @Override
    public void prepareAllCreatures() {
        for (CreatureCard c : getCreaturesOnTable()) {
            c.unsetSummoningSickness();
        }
    }

    @Override
    public boolean putLandOnTable(LandCard landCard) {
        if (hand.contains(landCard) && !landCard.isOnTable()) {
            hand.remove(landCard);
            table.add(landCard);
            landCard.putOnTable();
            return true;
        }
        return false;
    }

    @Override
    public boolean putCreatureOnTable(CreatureCard creatureCard) {
        if (hand.contains(creatureCard) && !creatureCard.isOnTable() && hasManaForCreature(creatureCard)) {
            tapManaForCreature(creatureCard);
            hand.remove(creatureCard);
            table.add(creatureCard);
            creatureCard.putOnTable();
            return true;
        }
        return false;
    }

    @Override
    public boolean hasManaForCreature(CreatureCard creature) {
        boolean flag = true;
        int[] untapped = calculateUntappedLands();
        for (ManaType t : ManaType.values()) {
            if (creature.getSpecialCost(t) > untapped[t.ordinal()]) {
                flag = false;
            }
        }
        return flag;
    }

    @Override
    public int[] calculateUntappedLands() {
        int[] out = new int[5];
        for (LandCard c : getLandsOnTable()) {
            if (!c.isTapped()) {
                out[c.getManaType().ordinal()] += 1;
            }
        }

        return out;
    }

    private int[] creatureCost(CreatureCard creature) {
        int[] out = new int[5];
        for (ManaType t : ManaType.values()) {
            out[t.ordinal()] = creature.getSpecialCost(t);
        }
        return out;
    }

    private void tapManaCards(ManaType mana, int amount) {
        for (LandCard c : getLandsOnTable()) {
            if (amount == 0) {
                return;
            }
            if (c.getManaType() == mana && !c.isTapped()) {
                c.tap();
                amount--;
            }
        }
    }

    @Override
    public void tapManaForCreature(CreatureCard creature) {
        if (!hasManaForCreature(creature)) {
            return;
        }
        int[] cost = creatureCost(creature);

        for (ManaType t : ManaType.values()) {
            tapManaCards(t, cost[t.ordinal()]);
        }
    }


    @Override
    public void destroyCreature(CreatureCard creature) {
        table.remove(creature);
    }

    @Override
    public String toString() {
        return name + '(' + lives + ')';
    }
}
