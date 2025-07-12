// Copyright (C) 2024 Paul Johnson
// Copyright (C) 2024-2025 Maxim Nesterov

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.

// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <Shared/StaticData.h>

#include <math.h>
#include <stdio.h>

#include <Shared/Utilities.h>

// clang-format off
struct rr_petal_base_stat_scale const offensive[rr_rarity_id_max] = {
    {1.0,      1.0      },
    {1.7,      2.0      },
    {2.9,      4.0      },
    {5.0,      8.0      },
    {8.5,       16      },
    {14.5,      48      },
    {24.6,     144      },
    {42.0,     432      },
    {63.0,     648      },
    {94.5,     972      },
    {141.75,   1458     },
    {212.625,  2187     },
    {318.937,  3280.5   },
    {478.406,  4920.75  },
    {717.609,  7381.125 },
    {1076.414, 11071.687}
};

struct rr_petal_base_stat_scale const defensive[rr_rarity_id_max] = {
    {1.0,        1.0    },
    {2.0,        1.7    },
    {4.0,        2.9    },
    {8.0,        5.0    },
    {16,         8.5    },
    {48,        14.5    },
    {144,       24.6    },
    {432,       42.0    },
    {648,       63.0    },
    {972,       94.5    },
    {1458,      141.75  },
    {2187,      212.625 },
    {3280.5,    318.937 },
    {4920.75,   478.406 },
    {7381.125,  717.609 },
    {11071.687, 1076.414}
};
/*
    rr_rarity_id_common,
    rr_rarity_id_unusual,
    rr_rarity_id_rare,
    rr_rarity_id_epic,
    rr_rarity_id_legendary,
    rr_rarity_id_mythic,
    rr_rarity_id_exotic,
    rr_rarity_id_ultimate,
    rr_rarity_id_quantum,
    rr_rarity_id_aurous,
    rr_rarity_id_eternal,
    rr_rarity_id_hyper,
    rr_rarity_id_sunshine,
    rr_rarity_id_nebula,
    rr_rarity_id_infinity,
    rr_rarity_id_calamity,
*/
struct rr_petal_data RR_PETAL_DATA[rr_petal_id_max] = {
//   id                     min_rarity              scale        dmg      hp   clump   cd 2cd  count
    {rr_petal_id_none,      rr_rarity_id_common,    offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_basic,     rr_rarity_id_common,    offensive, 10.0f,  15.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,2,3,3,3,4,4,5,5,6}},
    {rr_petal_id_pellet,    rr_rarity_id_common,    offensive,  8.0f,   5.0f,   0.0f,  13,  0, {1,2,2,3,3,3,5,5,6,6,6,6,6,6,6,6}},
    {rr_petal_id_fossil,    rr_rarity_id_common,    offensive,  5.0f, 100.0f,   0.0f, 100,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2}},
    {rr_petal_id_stinger,   rr_rarity_id_common,    offensive, 65.0f,   3.0f,  10.0f, 150,  0, {1,1,1,1,1,3,4,5,5,6,6,6,6,6,6,6}},
    {rr_petal_id_berry,     rr_rarity_id_rare,      offensive,  5.0f,   5.0f,  12.0f,  13,  0, {1,1,1,1,1,1,1,2,3,3,3,3,3,3,3,3}},
    {rr_petal_id_shell,     rr_rarity_id_rare,      offensive, 18.0f,  16.0f,   0.0f,  50, 13, {1,1,1,1,1,2,3,3,3,3,3,3,3,3,3,5}},
    {rr_petal_id_peas,      rr_rarity_id_rare,      offensive, 22.0f,  12.0f,   8.0f,  13, 12, {4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,6}},
    {rr_petal_id_leaf,      rr_rarity_id_unusual,   offensive,  9.0f,   8.0f,   8.0f,  38,  0, {1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3}},
    {rr_petal_id_egg,       rr_rarity_id_unusual,   defensive,  0.0f,  75.0f,  10.0f,  25,100, {3,3,3,2,2,2,2,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_magnet,    rr_rarity_id_common,    defensive,  2.0f,  25.0f,   0.0f,  38,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2}},
    {rr_petal_id_uranium,   rr_rarity_id_rare,      offensive,  3.0f,  40.0f,   0.0f,  25, 25, {1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3}},
    {rr_petal_id_feather,   rr_rarity_id_common,    defensive,  1.0f,   3.0f,   0.0f,  25,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2}},
    {rr_petal_id_azalea,    rr_rarity_id_common,    defensive,  5.0f,  15.0f,  10.0f,  25, 50, {1,1,1,1,1,1,3,3,3,3,3,5,5,5,5,6}},
    {rr_petal_id_bone,      rr_rarity_id_common,    defensive,  2.5f,  25.0f,   0.0f,  68,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_web,       rr_rarity_id_rare,      defensive,  5.0f,   5.0f,   0.0f,  50, 13, {1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3}},
    {rr_petal_id_seed,      rr_rarity_id_legendary, defensive,  1.0f,  75.0f,   0.0f,  63,  1, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_gravel,    rr_rarity_id_unusual,   offensive,  9.0f,  20.0f,   0.0f,  20, 10, {1,2,2,2,3,3,3,3,3,3,3,3,5,5,5,5}},
    {rr_petal_id_club,      rr_rarity_id_common,    defensive,  8.0f, 600.0f,   0.0f, 250,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_crest,     rr_rarity_id_rare,      offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_droplet,   rr_rarity_id_common,    offensive, 15.0f,   5.0f,   0.0f,  37,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_beak,      rr_rarity_id_unusual,   defensive,  0.0f,  10.0f,   0.0f,  55,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3}},
    {rr_petal_id_lightning, rr_rarity_id_unusual,   offensive,  10.5f,  1.0f,   0.0f,  63,  0, {1,1,1,1,1,1,1,1,1,1,2,2,2,3,3,3}},
    {rr_petal_id_third_eye, rr_rarity_id_legendary, offensive,  0.0f,   0.0f,   0.0f,   0,  0, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
    {rr_petal_id_nest,      rr_rarity_id_legendary, defensive,  5.0f,  25.0f,   0.0f, 125,  1, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_fireball,  rr_rarity_id_unusual,   offensive,260.0f,   1.0f,   0.0f, 600,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_meat,      rr_rarity_id_common,    offensive,  0.0f,1600.0f,   0.0f, 188, 13, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_bubble,    rr_rarity_id_common,    defensive,  1.0f,  25.0f,   0.0f,  88,  3, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_meteor,    rr_rarity_id_unusual,   defensive,  0.0f,   0.0f,   0.0f,  50,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_mandible,  rr_rarity_id_common,    offensive,  5.0f,  10.0f,   0.0f,  75,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,3}},
    {rr_petal_id_wax,       rr_rarity_id_unusual,   offensive, 10.0f,  10.0f,  10.0f,  38,  0, {2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,5}},
    {rr_petal_id_sand,      rr_rarity_id_common,    offensive, 15.0f,  10.0f,  10.0f,  37,  0, {4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,6}},
    {rr_petal_id_mint,      rr_rarity_id_unusual,   offensive,  5.0f,  10.0f,  10.0f,  50, 25, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_pearl,     rr_rarity_id_mythic,    offensive, 450.0f,225.0f,   0.0f,9000,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_rice,      rr_rarity_id_calamity,  offensive,   2.0f,  0.1f,   0.0f,   0,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
    {rr_petal_id_sapphire,  rr_rarity_id_eternal,   offensive,   0.0f, 55.0f,   0.0f, 250,  0, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}},
};    

char const *RR_PETAL_NAMES[rr_petal_id_max] = {
    "Secret",   "Petal",     "Pellet",    "Fossil", "Stinger",  "Berry",   "Shell",
    "Peas",     "Leaf",      "Egg",       "Magnet", "Uranium",  "Feather", "Azalea",
    "Bone",     "Web",       "Seed",      "Gravel", "Club",     "Crest",   "Droplet",
    "Beak",     "Lightning", "Third Eye", "Nest",   "Fireball", "Meat",    "Bubble",
    "Meteor",   "Mandible",  "Wax",       "Sand",   "Mint",     "Pearl",   "Rice",
    "Sapphire",
};
    
char const *RR_PETAL_DESCRIPTIONS[rr_petal_id_max] = {
    0,
    "It's just a petal",
    "Low damage, but there's lots",
    "It came from a dino",
    "Ow that hurts",
    "Gives your other petals more energy",
    "Poor snail",
    "Splits in 4. Or maybe 5 if you're a pro. Or maybe more if...",
    "Heals you gradually",
    "Spawns a pet dinosaur to protect you",
    "Increases loot pickup radius. Stacks diminishingly",
    "Does damage to the owner and enemies in a large range",
    "It's so light it increases your movement speed. Stacks diminishingly",
    "It heals you",
    "Gives the player armor. Stacks diminishingly",
    "It slows everything down",
    "What does this one do",
    "Tiny rocks that stay on the ground and trip dinos",
    "Heavy and sturdy",
    "Increases your maximum vision range. Does not stack",
    "This mysterious petal reverses your petal rotation",
    "Stuns mobs and prevents them from moving",
    "A stunning display",
    "Your petals hate it and want to move further away. Stacks diminishingly",
    "Home sweet home",
    "Nice ball bro",
    "Meat meta",
    "Pop and you're gone",
    "Spawns a pet meteor to protect you",
    "Does more damage if target hp is below 50%",
    "Made by the bees",
    "Very fine",
    "Remember to feed your pets"
};

struct rr_mob_data RR_MOB_DATA[rr_mob_id_max] = {
//   id                                     min_rarity  max_rarity              hp dmg    rad  ai_passive_rarity    ai_neutral_rarity    ai_aggro_rarity       loot
    {rr_mob_id_triceratops,        rr_rarity_id_common, rr_rarity_id_calamity,  45, 15, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_leaf,    0.15},{rr_petal_id_fossil,    0.05}}},
    {rr_mob_id_trex,               rr_rarity_id_common, rr_rarity_id_calamity,  40, 25, 32.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_unusual, {{rr_petal_id_stinger, 0.03},{rr_petal_id_egg,       0.05},{rr_petal_id_meat,      0.01}}},
    {rr_mob_id_fern,               rr_rarity_id_common, rr_rarity_id_calamity,  10,  5, 24.0f, rr_rarity_id_max,    rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_leaf,     0.1},{rr_petal_id_azalea,    0.25},{rr_petal_id_sapphire, 0.005}}},
    {rr_mob_id_tree,               rr_rarity_id_common, rr_rarity_id_calamity, 100,  5, 64.0f, rr_rarity_id_max,    rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_leaf,     2.5},{rr_petal_id_peas,       2.5},{rr_petal_id_seed,      0.05}}}, // :trol:
    {rr_mob_id_pteranodon,         rr_rarity_id_common, rr_rarity_id_calamity,  40, 15, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_rare,    {{rr_petal_id_shell,   0.05},{rr_petal_id_beak,      0.15},{rr_petal_id_nest,      0.01}}},
    {rr_mob_id_dakotaraptor,       rr_rarity_id_common, rr_rarity_id_calamity,  35, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_epic,    {{rr_petal_id_crest,    0.1},{rr_petal_id_feather,    0.1},{rr_petal_id_pellet,    0.05}}},
    {rr_mob_id_pachycephalosaurus, rr_rarity_id_common, rr_rarity_id_calamity,  35, 20, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_common,  {{rr_petal_id_fossil,   0.1},{rr_petal_id_berry,      0.1},{rr_petal_id_web,       0.05}}},
    {rr_mob_id_ornithomimus,       rr_rarity_id_common, rr_rarity_id_calamity,  25, 10, 20.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_feather,  0.1},{rr_petal_id_droplet,   0.05},{rr_petal_id_pellet,     0.1}}},
    {rr_mob_id_ankylosaurus,       rr_rarity_id_common, rr_rarity_id_calamity,  50, 10, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_club,    0.15},{rr_petal_id_gravel,    0.05},{rr_petal_id_bubble,     0.1},{rr_petal_id_pearl,  0.005}}},
    {rr_mob_id_meteor,             rr_rarity_id_common, rr_rarity_id_calamity, 100, 10, 32.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_magnet,   0.5},{rr_petal_id_uranium,   0.05},{rr_petal_id_fireball,   1.0},{rr_petal_id_meteor, 2.0}}},
    {rr_mob_id_quetzalcoatlus,     rr_rarity_id_common, rr_rarity_id_calamity,  65, 20, 28.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_common,  {{rr_petal_id_beak,    0.05},{rr_petal_id_fossil,     0.1},{rr_petal_id_lightning, 0.01}}},
    {rr_mob_id_edmontosaurus,      rr_rarity_id_common, rr_rarity_id_calamity,  50, 15, 30.0f, rr_rarity_id_common, rr_rarity_id_common, rr_rarity_id_max,     {{rr_petal_id_bone,    0.01},{rr_petal_id_fossil,     0.1},{rr_petal_id_third_eye, 0.05}}},
    {rr_mob_id_ant,                rr_rarity_id_common, rr_rarity_id_calamity,  10, 10, 20.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_pellet,   0.1},{rr_petal_id_leaf,       0.1},{rr_petal_id_mandible,  0.05},{rr_petal_id_rice,   0.5}}},
    {rr_mob_id_hornet,             rr_rarity_id_common, rr_rarity_id_calamity,  28, 25, 25.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_stinger,  0.1},{rr_petal_id_crest,     0.05}}},
    {rr_mob_id_dragonfly,          rr_rarity_id_common, rr_rarity_id_calamity,  20, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_pellet,   0.1},{rr_petal_id_magnet,    0.05}}},
    {rr_mob_id_honeybee,           rr_rarity_id_common, rr_rarity_id_calamity,  12, 25, 22.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_wax,     0.05},{rr_petal_id_stinger,   0.05}}},
    {rr_mob_id_beehive,            rr_rarity_id_common, rr_rarity_id_calamity,   0,  0, 45.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_wax,     0.05},{rr_petal_id_azalea,    0.05}}},
    {rr_mob_id_spider,             rr_rarity_id_common, rr_rarity_id_calamity,  20, 25, 25.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_web,      0.1},{rr_petal_id_third_eye, 0.01}}},
    {rr_mob_id_house_centipede,    rr_rarity_id_common, rr_rarity_id_calamity,  25, 10, 23.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_peas,     0.1},{rr_petal_id_sand,      0.05}}},
    {rr_mob_id_lanternfly,         rr_rarity_id_common, rr_rarity_id_calamity,  20, 10, 25.0f, rr_rarity_id_common, rr_rarity_id_max,    rr_rarity_id_max,     {{rr_petal_id_mint,     0.1},{rr_petal_id_sand,      0.05}}},
};

char const *RR_MOB_NAMES[rr_mob_id_max] = {
"Triceratops","T-Rex","Fern","Tree","Pteranodon","Dakotaraptor",
"Pachycephalosaurus","Ornithomimus","Ankylosaurus","Meteor",
"Quetzalcoatlus","Edmontosaurus","Ant","Hornet","Dragonfly",
"Honeybee","Beehive","Spider","House Centipede","Lanternfly"
};

uint32_t RR_MOB_DIFFICULTY_COEFFICIENTS[rr_mob_id_max] = {
    3, //tric
    4, //trex
    1, //fern
    2, //tree
    5, //pter
    5, //dako
    3, //pachy
    2, //ornith
    4, //anky
    1, //meteor
    5, //quetz
    3, //edmo
};

double RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {
    50,   //tric
    100,  //trex
    15,   //fern
    0.75, //tree
    75,   //pter
    50,   //dako
    25,   //pachy
    40,   //ornith
    25,   //anky
    25,    //meteor
    75,   //quetz
    25,   //edmo
};
double RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 10};

struct rr_petal_rarity_scale RR_PETAL_RARITY_SCALE[rr_rarity_id_max] = {
    {1,     240,    45   },
    {1.8,   120,    60   },
    {3.5,   60,     75   },
    {6.8,   30,     100  },
    {12.5,  15,     125  },
    {24.5,  7.5,    150  },
    {60,    2.5,    200  },
    {180,   0.5,    250  },
    {240,   0.2,    325  },
    {390,   0.1,    485  },
    {510,   0.05,   821  },
    {850,   0.025,  1800 },
    {1010,  0.01,   3010 },
    {1200,  0.005,  4850 },
    {1640,  0.001,  6990 },
    {2800,  0.0005, 9800 }
};

struct rr_mob_rarity_scale RR_MOB_RARITY_SCALING[rr_rarity_id_max] = {
    {1,       1,       1  },
    {2.4,     1.7,     1.2},
    {6,       2.9,     1.5}, 
    {14.4,    5,       2  },
    {40,      8.5,     2.8},
    {192,     14.5,    4  },
    {2560,    24.6,    5.5},
    {51200,   42,      7  }, // 128000
    {256000,  84,      12 },
    {405000,  205,     18 },
    {930000,  709,     24 },
    {1110000, 1401,    37 },
    {1600000, 3940,    50 },
    {2500000, 8060,    59 },
    {3750000, 13500,   66 },
    {7000000, 37800,   75 }
};
// clang-format on

uint32_t RR_RARITY_COLORS[rr_rarity_id_max] = {
    0xff7eef6d, 0xffffe65d, 0xff4d52e3, 0xff861fde,
    0xffde1f1f, 0xff1fdbde, 0xffff2b75, 0xffff00ff, /* 0xff2bffa3,*/
    0xfface3df, 0xffd1ab38, 0xff8d9ac9, 0xff467330,
    0xffc29c5b, 0xff4914a6, 0xff3d3d3d, 0xff852121};

char const *RR_RARITY_NAMES[rr_rarity_id_max] = {
    "Common",    "Unusual", "Rare",     "Epic",
    "Legendary", "Mythic",  "Exotic",   "Ultimate",
    "Quantum",   "Auruos",  "Eternal",  "Hyper",
    "Sunshine",  "Nebula",  "Infinity", "Calamity"};

double RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_max + 1] = {
    0,     1,     6,     10,
    15,    25,    160,   1200,
    2800,  4000,  9300,  12000,
    21000, 39000, 56000, 70000};

/*
double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_nebula + 2] = {
    0,     1,     9,     17,
    45,    175,   690,   3000,
    8400,  13800, 19900, 26000,
    41250, 58000, 70050};

double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {2.5,  4,    6,    15,
                                                            35,   100,  125,  150,
                                                            240,  545,  980,  1520,
                                                            2325, 3970, 5250, 9660};
*/
/*
double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_nebula + 2] = {
    0,     1,     8,     15,
    40,    150,   500,   2500,
    6100,  9000,  13500, 20000,
    32000, 42000, 55000};
double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {2.5,  4,    6,    15,
                                                            35,   100,  125,  150,
                                                            240,  480,  900,  1200,
                                                            1600, 2500, 4200, 6000};
*/

double RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_nebula + 2] = {
    0,     1,     8,     15,
    40,    150,   500,   2500,
    6100,  9000,  13500, 20000,
    32000, 42000, 55000};
double RR_MOB_LOOT_RARITY_COEFFICIENTS[rr_rarity_id_max] = {2.5,  4,    6,    15,
                                                            35,   140,  490,  2150,
                                                            5240,  8480,  12900,  18200,
                                                            30600, 40500, 50200, 9400};

static void init_game_coefficients()
{
    double sum = 1;
    double sum2 = 1;
    for (uint64_t a = 1; a < rr_rarity_id_max; ++a)
        RR_MOB_LOOT_RARITY_COEFFICIENTS[a] *=
            RR_MOB_LOOT_RARITY_COEFFICIENTS[a - 1];
    for (uint64_t a = 1; a <= rr_rarity_id_nebula; ++a)
    {
        sum += (RR_DROP_RARITY_COEFFICIENTS[a + 1] =
                    RR_DROP_RARITY_COEFFICIENTS[a] /
                    RR_DROP_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_nebula + 1; ++a)
    {
        RR_DROP_RARITY_COEFFICIENTS[a] = RR_DROP_RARITY_COEFFICIENTS[a] / sum +
                                         RR_DROP_RARITY_COEFFICIENTS[a - 1];
    }
    RR_DROP_RARITY_COEFFICIENTS[rr_rarity_id_nebula + 1] = 1;
    for (uint64_t a = 1; a <= rr_rarity_id_infinity; ++a)
    {
        sum2 += (RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1] =
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a] /
                     RR_MOB_WAVE_RARITY_COEFFICIENTS[a + 1]);
    }
    for (uint64_t a = 1; a <= rr_rarity_id_infinity + 1; ++a)
    {
        RR_MOB_WAVE_RARITY_COEFFICIENTS[a] =
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a] / sum2 +
            RR_MOB_WAVE_RARITY_COEFFICIENTS[a - 1];
    }
    RR_MOB_WAVE_RARITY_COEFFICIENTS[rr_rarity_id_infinity + 1] = 1;
    for (uint64_t mob = 1; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] +=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob - 1];
    }
    for (uint64_t mob = 0; mob < rr_mob_id_max; ++mob)
    {
        RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_HELL_CREEK_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
        RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[mob] /=
            RR_GARDEN_MOB_ID_RARITY_COEFFICIENTS[rr_mob_id_max - 1];
    }
}

#define offset(a, b)                                                           \
    ((x + a < 0 || y + b < 0 || x + a >= size / 2 || y + b >= size / 2)        \
         ? 0                                                                   \
         : template[(y + b) * size / 2 + x + a])
#define maze_grid(x, y) maze[(y)*size + (x)]

static void init_maze(uint32_t size, uint8_t *template,
                      struct rr_maze_grid *maze)
{
    for (int32_t y = 0; y < size / 2; ++y)
    {
        for (int32_t x = 0; x < size / 2; ++x)
        {
            uint8_t this_tile = offset(0, 0);
#ifdef RR_SERVER
            maze_grid(x * 2, y * 2).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2).difficulty = this_tile;
            maze_grid(x * 2, y * 2 + 1).difficulty = this_tile;
            maze_grid(x * 2 + 1, y * 2 + 1).difficulty = this_tile;
#endif
            this_tile = this_tile != 0;
            // top left
            uint8_t top = offset(0, -1);
            uint8_t bottom = offset(0, 1);
            if (this_tile)
            {
                if (top == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2).value = 7;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2).value = 5;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom == 0)
                {
                    if (offset(-1, 0) == 0)
                        maze_grid(x * 2, y * 2 + 1).value = 6;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) == 0)
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 4;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
            else
            {
                if (top)
                {
                    if (offset(-1, 0) && offset(-1, -1))
                        maze_grid(x * 2, y * 2).value = 15;
                    else
                        maze_grid(x * 2, y * 2).value = this_tile;
                    if (offset(1, 0) && offset(1, -1))
                        maze_grid(x * 2 + 1, y * 2).value = 13;
                    else
                        maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2).value = this_tile;
                }
                if (bottom)
                {
                    if (offset(-1, 0) && offset(-1, 1))
                        maze_grid(x * 2, y * 2 + 1).value = 14;
                    else
                        maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    if (offset(1, 0) && offset(1, 1))
                        maze_grid(x * 2 + 1, y * 2 + 1).value = 12;
                    else
                        maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
                else
                {
                    maze_grid(x * 2, y * 2 + 1).value = this_tile;
                    maze_grid(x * 2 + 1, y * 2 + 1).value = this_tile;
                }
            }
        }
    }
}

static void print_chances(float difficulty)
{
    printf("-----Chances for %.0f-----\n", difficulty);
    uint32_t rarity_cap = rr_rarity_id_common + (difficulty + 7) / 8;
    if (rarity_cap > rr_rarity_id_calamity)
        rarity_cap = rr_rarity_id_calamity;
    uint32_t rarity = rarity_cap >= 2 ? rarity_cap - 2 : 0;
    for (; rarity <= rarity_cap; ++rarity)
    {
        float start =
            rarity == 0
                ? 0
                : pow(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity]) * 0.3,
                      pow(1.5, difficulty));
        float end =
            rarity == rarity_cap
                ? 1
                : pow(1 - (1 - RR_MOB_WAVE_RARITY_COEFFICIENTS[rarity + 1]) *
                              0.3,
                      pow(1.5, difficulty));
        printf("%s: %.9f (1 per %.4f)\n", RR_RARITY_NAMES[rarity], end - start,
               1 / (end - start));
    }
}

double RR_BASE_CRAFT_CHANCES[rr_rarity_id_max - 1] = {0.5,   0.4,   0.3,  0.2,
                                                      0.1,   0.08,  0.06, 0.05,
                                                      0.04,  0.03,  0.02, 0.01,
                                                      0.009, 0.008, 0.007};
double RR_CRAFT_CHANCES[rr_rarity_id_max - 1];

static double from_prd_base(double C)
{
    double pProcOnN = 0;
    double pProcByN = 0;
    double sumNpProcOnN = 0;

    double maxFails = ceil(1 / C);
    for (uint32_t N = 1; N <= maxFails; ++N)
    {
        pProcOnN = fmin(1, N * C) * (1 - pProcByN);
        pProcByN += pProcOnN;
        sumNpProcOnN += N * pProcOnN;
    }
    return (1 / sumNpProcOnN);
}

static double get_prd_base(double p)
{
    if (p == 0)
        return 0;
    double Cupper = p;
    double Clower = 0;
    double Cmid = p / 2;
    double p1 = 0;
    double p2 = 1;
    while (1)
    {
        Cmid = (Cupper + Clower) / 2;
        p1 = from_prd_base(Cmid);
        if (fabs(p1 - p2) <= 0)
            break;

        if (p1 > p)
            Cupper = Cmid;
        else
            Clower = Cmid;
        p2 = p1;
    }
    return Cmid;
}

#define init(MAZE)                                                             \
    init_maze(sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid),         \
              &RR_MAZE_TEMPLATE_##MAZE[0][0], &RR_MAZE_##MAZE[0][0]);

void rr_static_data_init()
{
    for (uint32_t r = 0; r < rr_rarity_id_max - 1; ++r)
        RR_CRAFT_CHANCES[r] = get_prd_base(RR_BASE_CRAFT_CHANCES[r]);
    init_game_coefficients();
    init(HELL_CREEK);
    init(BURROW);
#ifdef RR_SERVER
    print_chances(1);   // c
    print_chances(4);   // C
    print_chances(8);   // u
    print_chances(12);  // U
    print_chances(16);  // r
    print_chances(20);  // R
    print_chances(24);  // e
    print_chances(28);  // E
    print_chances(32);  // l
    print_chances(36);  // L
    print_chances(40);  // m
    print_chances(44);  // M
    print_chances(48);  // x
    print_chances(52);  // X
    print_chances(56);  // a
    print_chances(60);  // A
    print_chances(64);  // q
    print_chances(68);  // Q
    print_chances(72);  // au
    print_chances(76);  // AU
    print_chances(80);  // et
    print_chances(84);  // ET
    print_chances(88);  // h
    print_chances(92);  // H
    print_chances(96);  // s
    print_chances(100); // S
    print_chances(104); // n
    print_chances(108); // N
    print_chances(112); // i
    print_chances(116); // I
    print_chances(120); // cal
    print_chances(124); // CAL
#endif
}

double xp_to_reach_level(uint32_t level)
{
    if (level <= 60)
        return (level + 5) * pow(1.175, level);
    double base = (level + 5) * pow(1.175, 60);
    for (uint32_t i = 60; i < level; ++i)
        base *= rr_fclamp(1.18 - 0.0075 * (i - 60), 1.1, 1.18);
    return base;
}

uint32_t level_from_xp(double xp)
{
    uint32_t level = 1;
    while (xp >= xp_to_reach_level(level + 1))
        xp -= xp_to_reach_level(++level);
    return level;
}

#ifdef RR_SERVER
#define _ 0
#define c 1
#define C 4
#define u 8
#define U 12
#define r 16
#define R 20
#define e 24
#define E 28
#define l 32
#define L 36
#define m 40
#define M 44
#define x 48
#define X 52
#define a 56
#define A 60

#define q 64
#define Q 68
#define au 72
#define AU 76
#define et 80
#define ET 84
#define h 88
#define H 92
#define s 96
#define S 100
#define n 104
#define N 108
#define i 112
#define I 116
#define cal 120
#define CAL 124
#else
#define _ 0
#define c 1
#define C 1
#define u 1
#define U 1
#define r 1
#define R 1
#define e 1
#define E 1
#define l 1
#define L 1
#define m 1
#define M 1
#define x 1
#define X 1
#define a 1
#define A 1

#define q 1
#define Q 1
#define au 1
#define AU 1
#define et 1
#define ET 1
#define h 1
#define H 1
#define s 1
#define S 1
#define n 1
#define N 1
#define i 1
#define I 1
#define cal 1
#define CAL 1
#endif

#define RR_DEFINE_MAZE(name, size)                                             \
    struct rr_maze_grid RR_MAZE_##name[size][size];                            \
    uint8_t RR_MAZE_TEMPLATE_##name[size / 2][size / 2]
// clang-format off
RR_DEFINE_MAZE(HELL_CREEK, 80) = {
//                     11  13  15  17  19  21  23  25  27  29  31  33  35  37  39
// 1 2 3 4 5 6 7 8 9 10  12  14  16  18  20  22  24  26  28  30  32  34  36  38
{_,_,_,_,_,x,x,x,x,_,_,_,_,_,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,X,_,_,_,_,_},
{_,M,M,_,_,_,_,x,x,x,x,M,M,M,x,_,_,_,_,_,x,_,_,_,_,_,_,_,_,x,_,_,x,X,X,X,X,_,_,_},
{m,m,M,M,_,_,_,_,_,_,_,_,M,_,_,_,_,X,X,_,x,x,x,_,x,x,x,x,x,x,_,_,_,_,X,X,X,X,_,_},
{m,m,m,M,M,M,M,M,M,M,M,M,M,_,_,X,X,X,x,x,x,_,x,x,x,_,_,x,x,x,x,x,_,X,X,X,X,X,_,_},
{m,m,m,_,_,_,_,_,_,_,_,_,_,_,X,X,X,X,X,_,x,_,_,x,x,_,_,_,_,x,x,_,_,X,X,X,X,X,X,_},
{m,m,_,_,_,_,_,R,R,R,_,_,_,_,_,X,X,X,_,_,x,_,_,_,x,_,x,x,_,_,x,_,_,_,X,X,X,_,_,_},
{m,m,_,_,_,R,R,R,r,R,r,r,r,_,_,_,X,X,_,_,_,_,_,_,x,x,x,x,_,_,x,_,x,_,_,X,_,_,_,_},
{m,_,_,_,R,R,E,E,E,r,_,_,r,_,_,_,_,X,X,_,_,_,_,_,x,_,x,x,x,_,x,_,x,M,_,_,_,_,_,_},
{m,_,_,l,l,E,E,E,E,r,_,r,r,r,r,_,_,X,X,X,_,_,_,x,x,_,x,x,X,_,M,_,M,M,M,M,_,_,_,_},
{m,_,m,l,l,_,l,E,E,_,_,r,_,_,r,_,X,X,X,X,X,X,_,_,x,_,_,X,X,_,M,_,_,M,M,M,M,_,_,_},
{m,_,x,m,_,_,_,_,C,_,R,R,_,r,r,_,X,X,_,_,_,X,_,_,x,x,_,_,_,_,M,_,_,_,M,M,M,M,_,_},
{m,_,_,_,_,_,_,_,C,_,_,_,_,u,_,_,X,X,_,X,X,X,_,_,x,x,x,_,_,M,M,_,_,_,_,_,_,M,_,_},
{m,_,_,_,_,c,c,c,C,C,C,u,u,u,_,_,X,X,_,_,_,X,_,_,_,x,M,M,M,M,M,_,_,M,M,_,M,M,_,_},
{m,_,_,_,_,c,c,c,_,_,r,r,r,_,_,_,X,X,_,_,_,X,_,_,_,x,x,_,_,_,M,M,M,M,M,M,M,_,_,_},
{m,_,_,_,_,c,c,c,_,r,r,u,r,r,_,_,X,X,X,X,X,X,_,_,_,_,_,_,_,_,_,M,M,M,M,M,M,_,_,_},
{m,_,_,_,_,_,_,C,_,r,r,r,r,r,_,_,_,_,X,X,X,_,_,_,_,_,_,M,M,M,_,_,_,M,_,M,m,_,_,_},
{m,m,m,m,m,m,_,C,_,_,r,r,r,r,_,l,l,_,_,_,_,_,L,L,L,_,_,_,M,M,M,M,_,M,_,_,m,m,_,_},
{L,_,_,_,_,m,_,C,r,_,_,_,_,r,l,l,l,l,l,l,l,l,L,_,L,m,M,_,M,M,M,M,M,M,m,_,m,m,m,_},
{L,L,_,m,m,m,_,_,r,r,r,r,_,_,_,_,_,_,l,l,_,_,L,_,_,_,L,_,_,M,M,M,_,_,m,m,m,m,m,_},
{_,L,_,_,L,m,_,e,e,_,_,e,e,e,e,_,m,m,m,m,_,_,L,m,_,_,M,_,_,_,M,M,M,_,_,m,m,m,m,_},
{_,L,L,L,L,_,_,e,e,_,_,e,m,E,E,m,m,m,M,M,_,_,_,m,L,M,L,L,_,_,_,_,_,_,_,_,_,_,m,_},
{L,L,_,_,_,_,_,e,e,e,_,e,E,_,E,E,_,_,M,M,M,_,_,_,_,_,L,m,M,L,L,_,_,_,_,x,_,_,m,_},
{L,_,_,_,_,_,_,_,e,E,_,l,_,_,l,l,l,_,_,m,M,L,L,_,_,_,M,M,_,L,L,m,_,_,X,x,x,_,m,_},
{L,_,_,_,x,x,x,_,_,E,_,l,_,_,l,l,l,_,_,L,_,L,L,L,_,_,L,_,_,_,_,m,_,x,x,X,A,_,m,_},
{m,_,_,x,x,x,x,x,_,_,_,l,_,_,_,l,l,_,L,L,_,L,L,L,_,m,L,_,X,_,_,m,M,x,x,x,_,_,m,_},
{m,_,x,x,X,X,x,x,_,_,_,l,_,_,_,l,l,_,L,L,_,L,L,_,_,m,_,_,X,X,_,m,_,_,_,_,_,_,m,_},
{m,x,x,x,X,X,x,x,_,_,_,L,L,L,_,_,L,_,L,L,_,_,L,_,_,m,_,_,X,X,_,m,m,_,_,_,_,m,m,_},
{m,_,x,x,x,x,x,_,_,_,L,L,L,L,L,_,L,_,_,L,L,L,L,_,_,m,_,_,X,X,M,M,m,m,_,_,m,m,m,_},
{m,_,_,x,x,x,_,_,_,_,L,L,L,L,L,_,L,_,_,m,m,m,m,_,_,m,_,_,_,_,_,M,M,M,_,_,m,m,_,_},
{m,_,_,_,l,_,_,_,_,_,M,M,M,M,M,_,m,m,_,_,m,m,m,_,_,m,x,m,m,_,_,_,m,m,_,_,m,M,_,_},
{M,M,_,_,l,_,_,_,_,_,M,M,x,M,M,_,m,m,_,_,_,m,m,_,_,_,m,m,m,m,m,m,x,m,_,L,m,m,_,_},
{M,M,_,_,l,l,_,_,_,_,_,M,x,M,_,_,m,m,m,m,_,_,m,m,_,_,m,M,x,M,_,_,_,_,_,_,_,M,_,_},
{M,M,_,_,l,l,l,l,_,_,_,_,_,_,_,_,m,m,m,m,m,m,m,m,_,_,m,m,m,m,_,_,x,x,x,M,M,M,_,_},
{_,M,x,_,_,l,l,x,l,l,l,_,_,_,_,_,m,E,E,m,_,_,m,m,_,_,m,M,m,_,_,_,x,_,_,_,_,M,_,_},
{_,x,x,_,_,_,_,l,l,l,E,E,x,E,E,E,E,E,E,E,E,_,m,m,_,_,m,m,_,_,_,_,X,_,A,A,_,M,_,_},
{_,x,x,x,X,_,_,_,_,l,l,E,E,E,_,_,_,_,_,_,E,E,l,m,m,_,M,x,m,_,_,_,X,_,_,a,_,M,_,_},
{_,x,x,X,X,a,a,_,_,_,_,_,_,_,_,_,_,_,_,_,E,l,l,l,l,m,m,m,m,_,_,_,X,X,X,a,_,m,_,_},
{_,_,X,X,X,a,a,a,_,_,_,_,_,_,_,_,AU,AU,_,_,_,l,l,l,_,l,l,l,l,_,_,_,_,_,_,_,_,M,_,_},
{_,_,_,X,a,a,a,a,a,_,A,A,A,A,au,au,AU,AU,_,_,_,_,_,_,_,l,l,x,l,l,l,L,x,M,m,m,m,m,_,_},
{_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_}
};
// clang-format on
RR_DEFINE_MAZE(BURROW, 4) = {{1, 1}, {0, 1}};

#define MAZE_ENTRY(MAZE, GRID_SIZE)                                            \
    (sizeof(RR_MAZE_##MAZE[0]) / sizeof(struct rr_maze_grid)), GRID_SIZE,      \
        &RR_MAZE_##MAZE[0][0]

struct rr_maze_declaration RR_MAZES[rr_biome_id_max] = {
    {MAZE_ENTRY(HELL_CREEK, 1024), {{6, 13}, {11, 15}, {16, 17}, {22, 23}}},
    {MAZE_ENTRY(HELL_CREEK, 1024), {{6, 13}, {11, 15}, {16, 17}, {22, 23}}},
    {MAZE_ENTRY(BURROW, 512), {{0}, {0}, {0}, {0}}},
};

uint8_t RR_GLOBAL_BIOME = rr_biome_id_hell_creek;
#undef _
#undef c
#undef C
#undef u
#undef U
#undef r
#undef R
#undef e
#undef E
#undef l
#undef L
#undef m
#undef M
#undef x
#undef X
#undef a
#undef A
#undef q
#undef Q
#undef au
#undef AU
#undef et
#undef ET
#undef h
#undef H
#undef s
#undef S
#undef n
#undef N
#undef i
#undef I
#undef cal
#undef CAL
