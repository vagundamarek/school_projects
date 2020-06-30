package magicthegathering.impl;

import magicthegathering.game.Card;
import magicthegathering.game.CreatureCard;
import magicthegathering.game.Game;
import magicthegathering.game.Player;
import magicthegathering.game.Generator;

import java.util.HashSet;
import java.util.List;

/**
 * class implementing game
 *
 * @author Marek Vagunda
 */
public class GameImpl implements Game {
    private Player p1;
    private Player p2;
    private Player current;

    @Override
    public void initGame() {
        p1.initCards(Generator.generateCards());
        p2.initCards(Generator.generateCards());
    }

    @Override
    public void changePlayer() {
        if (current == p1) {
            current = p2;
        } else current = p1;
    }

    @Override
    public void prepareCurrentPlayerForTurn() {
        for (Card c : current.getCardsOnTable()) {
            c.untap();
        }
        for (CreatureCard c : current.getCreaturesOnTable()) {
            c.unsetSummoningSickness();
        }
    }

    @Override
    public Player getCurrentPlayer() {
        return current;
    }

    @Override
    public Player getSecondPlayer() {
        if (current == p1) {
            return p2;
        } else return p1;
    }

    @Override
    public void performAttack(List<CreatureCard> creatures) {
        for (CreatureCard c : creatures) {
            c.tap();
        }
    }


    @Override
    public boolean isCreaturesAttackValid(List<CreatureCard> attackingCreatures) {
        return isCreaturesAttackValid(attackingCreatures, true);
    }

    /**
     * checks if list is valid for attack before and after attack
     * @param attackingCreatures creature list
     * @param beforeAttack before/after switch
     * @return true if valid/false otherwise
     */
    private boolean isCreaturesAttackValid(List<CreatureCard> attackingCreatures, boolean beforeAttack) {
        for (CreatureCard c : attackingCreatures) {
            if (c == null || (beforeAttack && c.isTapped()) || c.hasSummoningSickness() ||
                    !current.getCardsOnTable().contains(c)) {
                return false;
            }
        }
        HashSet<CreatureCard> set = new HashSet<>();
        for (CreatureCard c : attackingCreatures) {
            if (!set.add(c)) {
                return false;
            }
        }
        return true;
    }


    @Override
    public boolean isCreaturesBlockValid(List<CreatureCard> attackingCreatures, List<CreatureCard> blockingCreatures) {

        boolean flag = isCreaturesAttackValid(attackingCreatures, false);

        flag &= (attackingCreatures.size() == blockingCreatures.size());
        int nullCount = 0;
        for (CreatureCard c : blockingCreatures) {
            if (c == null) {
                nullCount++;
            } else {
                flag &= !c.isTapped() && getSecondPlayer().getCardsOnTable().contains(c);
            }
        }
        if (nullCount < 2) {
            flag &= blockingCreatures.size() == new HashSet<>(blockingCreatures).size();
        } else {
            flag &= blockingCreatures.size() - nullCount + 1 == new HashSet<>(blockingCreatures).size();
        }
        return flag;
    }

    @Override
    public void performBlockAndDamage(List<CreatureCard> attackingCreatures, List<CreatureCard> blockingCreatures) {
        for (int i = 0; i < attackingCreatures.size(); i++) {
            if (blockingCreatures.get(i) == null) {
                getSecondPlayer().subtractLives(attackingCreatures.get(i).getPower());
            } else {
                if (attackingCreatures.get(i).getPower() >= blockingCreatures.get(i).getToughness()) {
                    if (attackingCreatures.get(i).getToughness() <= blockingCreatures.get(i).getPower()) {
                        getCurrentPlayer().destroyCreature(attackingCreatures.get(i));
                        getSecondPlayer().destroyCreature(blockingCreatures.get(i));
                    } else {
                        getSecondPlayer().destroyCreature(blockingCreatures.get(i));
                    }
                } else {
                    if (attackingCreatures.get(i).getToughness() <= blockingCreatures.get(i).getPower()) {
                        getCurrentPlayer().destroyCreature(attackingCreatures.get(i));
                    }
                }
            }

        }
    }

    /**
     * contructor
     *
     * @param p1 player1
     * @param p2 player2
     */
    public GameImpl(Player p1, Player p2) {
        if (p1 == null || p2 == null) {
            throw new IllegalArgumentException("null player");
        }
        this.p1 = p1;
        this.p2 = p2;
        current = p1;

    }
}
