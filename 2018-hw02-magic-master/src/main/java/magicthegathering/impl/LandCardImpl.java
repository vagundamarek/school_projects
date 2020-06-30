package magicthegathering.impl;

import magicthegathering.game.LandCard;
import magicthegathering.game.LandCardType;
import magicthegathering.game.ManaType;

import java.util.Objects;

/**
 * implements landcart class
 *
 * @author Marek Vagunda
 */
public class LandCardImpl extends CardImpl implements LandCard {

    private LandCardType type;

    /**
     * constructor
     *
     * @param type land type
     */
    public LandCardImpl(LandCardType type) {
        if (type == null) {
            throw new IllegalArgumentException("invalid type");
        }
        this.type = type;
    }

    @Override
    public LandCardType getLandType() {
        return type;
    }

    @Override
    public ManaType getManaType() {
        switch (type) {
            case PLAINS:
                return ManaType.WHITE;
            case MOUNTAIN:
                return ManaType.RED;
            case FOREST:
                return ManaType.GREEN;
            case ISLAND:
                return ManaType.BLUE;
            case SWAMP:
                return ManaType.BLACK;
            default:
        }
        return null;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        LandCardImpl landCard = (LandCardImpl) o;
        return type == landCard.type;
    }

    @Override
    public int hashCode() {
        return Objects.hash(type);
    }

    @Override
    public String toString() {
        return "Land " + type.toString().toLowerCase() + ", " + getManaType();
    }
}
