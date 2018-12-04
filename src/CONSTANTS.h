#ifndef CONSTANTS_H
#define CONSTANTS_H

#define VERSION std::string("A.2.0")
#define IP_ADDRESS sf::IpAddress("174.56.242.113")
#define PORT 51130

#define DISCORD_DETAILS "Making Client commands..."

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define MARGIN 30.f //
#define PADDING 10.f //
#define TAB_HEIGHT 20.f
#define MEMBERLIST_WIDTH 100.f
#define TYPEBOX_HEIGHT 50.f

#define CHATBOX_WIDTH WINDOW_WIDTH / 2.f - MARGIN - MEMBERLIST_WIDTH - 2 * PADDING
#define CHATBOX_HEIGHT WINDOW_HEIGHT - 2.f * MARGIN - TYPEBOX_HEIGHT - PADDING - TAB_HEIGHT
#define TYPEBOX_WIDTH CHATBOX_WIDTH + MEMBERLIST_WIDTH - TYPEBOX_HEIGHT

#define TEXT_SIZE 13

#define J_STR(x) x + " has joined!"
#define C_STR(x, y) x + " has changed their username to " + y
#define D_STR(x) x + " has disconnected!"

#define GENERAL_CHANNEL Channel("general", "General", Channel::PUBLIC_OOC)
#define NO_CHANNEL(x) Channel("na", "N/A", x)

enum Species
{
  NO_SPECIES,
  BULBASAUR,
  IVYSAUR,
  VENUSAUR,
  CHARMANDER,
  CHARMELEON,
  CHARIZARD,
  SQUIRTLE,
  WARTORTLE,
  BLASTOISE,

  VULPIX = 37,
  NINETALES,

  EEVEE = 133,
  VAPOREON,
  JOLTEON,
  FLAREON,
  PORYGON,

  ARCTICUNO = 144,
  ZAPDOS,
  MOLTRES,

  MEWTWO = 150,
  MEW,

  TOTODILE = 158,
  CROCONAW,
  FERALIGATR,

  ESPEON = 196,
  UMBREON,

  GLIGAR = 207,

  SWINUB = 220,
  PILOSWINE,

  PORYGON2 = 233,

  RAIKOU = 243,
  ENTEI,
  SUICUNE,

  LUGIA = 249,
  HO_OH,
  CELEBI,

  RALTS = 280,
  KIRLIA,
  GARDEVOIR,

  KECLEON = 352,

  REGIROCK = 377,
  REGICE,
  REGISTEEL,
  LATIAS,
  LATIOS,
  KYOGRE,
  GROUDON,
  RAYQUAZA,
  JIRACHI,
  DEOXYS,

  RIOLU = 447,
  LUCARIO,

  LEAFEON = 470,
  GLACEON,
  GLISCOR,
  MAMOSWINE,
  PORYGON_Z,
  GALLADE,

  ROTOM = 479,
  UXIE,
  MESPIRIT,
  AZELF,
  DIALGA,
  PALKIA,
  HEATRAN,
  REGIGIGAS,
  GIRATINA,
  CRESSELIA,
  PHIONE,
  MANAPHY,
  DARKRAI,
  SHAYMIN,
  ARCEUS,
  VICTINI,

  JOLTIK = 595,
  GALVANTULA,

  GOLETT = 622,
  GOLURK,

  COBALION = 638,
  TERRAKION,
  VIRIZION,
  TORNADUS,
  THUNDURUS,
  RESHIRAM,
  ZEKROM,
  LANDORUS,
  KYUREM,
  KELDEO,
  MELOETTA,
  GENESECT,

  SYLVEON = 700,

  XERNEAS = 716,
  YVELTAL,
  ZYGARDE,
  DIANCIE,
  HOOPA,
  VOLCANION,

  TAPU_KOKO = 785,
  TAPU_LELE,
  TAPU_BULU,
  TAPU_FINI,
  COSMOG,
  COSMOEM,
  SOLGALEO,
  LUNALA,
  NIHILEGO,
  BUZZWOLE,
  PHEROMOSA,
  XURKITREE,
  CELESTEELA,
  KARTANA,
  GUZZLORD,
  NECROZMA,
  MAGEARNA,
  MARSHADOW,
  POIPOLE,
  NAGANADEL,
  STAKATAKA,
  BLACEPHALON,
  ZERAORA
};

enum Type
{
  NO_TYPE,
  NORMAL,
  FIRE,
  WATER,
  ELECTRIC,
  GRASS,
  ICE,
  FIGHTING,
  POISON,
  GROUND,
  FLYING,
  PSYCHIC,
  BUG,
  ROCK,
  GHOST,
  DRAGON,
  DARK,
  STEEL,
  FAIRY,

  TYPE_COUNT
};

enum Status
{
  BLEED,
  BURN,
  SLEEP,
  POISON_STATUS,
  BAD_POISON,

  ENTANGLE,
  FLINCH,
  FREEZE,
  PARALYZE,
  SCARE,
  TERRIFY,

  CONFUSE,
  STAGGER,
  FAINT,

  STATUS_COUNT
};

#endif
