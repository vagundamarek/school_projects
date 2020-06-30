package magicthegathering.impl;


import magicthegathering.game.CreatureCard;
import magicthegathering.game.ManaType;

import java.util.List;
import java.util.Objects;

/**
 * implements creaturecard
 *
 * @author Marek Vagunda
 */
public class CreatureCardImpl extends CardImpl implements CreatureCard {
    private String name;
    private List<ManaType> cost;
    private int power;
    private int toughness;
    private boolean summoningSickness;

    /**
     * constructor
     *
     * @param name      name
     * @param cost      mana cost
     * @param power     power
     * @param toughness toughness
     */
    public CreatureCardImpl(String name, List<ManaType> cost, int power, int toughness) {
        super();
        if (name == null || name == "") {
            throw new IllegalArgumentException("invalid name");
        }
        if (cost == null) {
            throw new IllegalArgumentException("invalid cost");
        }
        if (power < 0) {
            throw new IllegalArgumentException("invalid power");
        }
        if (toughness < 1) {
            throw new IllegalArgumentException("invalid toughness");
        }
        this.name = name;
        this.cost = cost;
        this.power = power;
        this.toughness = toughness;
        summoningSickness = true;

    }

    @Override
    public int getSpecialCost(ManaType mana) {
        int specCost = 0;
        for (ManaType m : cost) {
            if (m == mana) {
                specCost++;
            }
        }
        return specCost;
    }

    @Override
    public int getTotalCost() {
        return cost.size();
    }

    @Override
    public int getPower() {
        return power;
    }

    @Override
    public int getToughness() {
        return toughness;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public boolean hasSummoningSickness() {
        return summoningSickness;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CreatureCardImpl that = (CreatureCardImpl) o;
        return getPower() == that.getPower() &&
                getToughness() == that.getToughness() &&
                Objects.equals(getName(), that.getName()) &&
                Objects.equals(cost, that.cost);
    }

    @Override
    public int hashCode() {
        return Objects.hash(getName(), cost, getPower(), getToughness());
    }

    @Override
    public void setSummoningSickness() {
        summoningSickness = true;
    }

    @Override
    public void unsetSummoningSickness() {
        summoningSickness = false;
    }


    @Override
    public String toString() {
        String out = name + " [";
        int i = 0;
        for (; i < getTotalCost() - 1; i++) {
            out += cost.get(i) + ", ";
        }
        out += cost.get(i) + "] ";

        out += power + " / " + toughness;
        if (!summoningSickness) {
            out += " can attack";
        }
        if (isTapped()) {
            out += " TAPPED";
        }
        return out;
    }
}
