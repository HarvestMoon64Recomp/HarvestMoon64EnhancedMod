// Fix for the farm ranking score calculation.
//
// The original calculateFarmRankingScore() sums a normalized contribution from
// every tracked stat (affections, shipments, gold, etc.), divides by 70 and
// stores the result in gFarmRankingData.scores[slot]. One term is wrong:
// wifeAffection is never counted because kaiAffection is added twice instead.
// This patch replaces the duplicate kaiAffection term with wifeAffection so the
// score reflects all relationships. Every other term is unchanged from the
// original.

#include "common.h"
#include "modding.h"

#include "game/game.h"
#include "game/gameFile.h"
#include "game/player.h"

extern s32 farmRankingRawScore;

RECOMP_PATCH void calculateFarmRankingScore(u8 slot) {

    f32 totalScore;

    gFarmRankingData.scores[slot] = 0.0f;

    totalScore = (((u32)gFarmRankingData.mariaAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.popuriAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.elliAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.annAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.karenAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.harrisAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.grayAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.jeffAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.cliffAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.kaiAffection[slot] * 100) / MAX_AFFECTION);

    // Bug fix: original had kaiAffection here
    totalScore += (((u32)gFarmRankingData.wifeAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.babyAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.dogAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.horseAffection[slot] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][0] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][1] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][2] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][3] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][4] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][5] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][6] * 100) / MAX_AFFECTION);
    totalScore += (((u32)gFarmRankingData.farmAnimalAffection[slot][7] * 100) / MAX_AFFECTION);

    totalScore += (((u32)gFarmRankingData.chickenCounts[slot] * 100) / 6);

    totalScore += ((gFarmRankingData.cropsShipped[slot] * 1000) / 99999);

    totalScore += ((gFarmRankingData.eggsShipped[slot] * 500) / 9999);

    totalScore += ((gFarmRankingData.milkShipped[slot] * 500) / 9999);

    totalScore += ((gFarmRankingData.fishCaught[slot] * 500) / 999);

    totalScore += ((gFarmRankingData.gold[slot] * 1000) / MAX_GOLD);

    totalScore += (((u32)gFarmRankingData.maxStamina[slot] * 100) / MAX_STAMINA);

    totalScore += (((u32)gFarmRankingData.photoCount[slot] * 25) / 4);

    totalScore += (((u32)gFarmRankingData.recipeCount[slot] * 100) / 35);

    totalScore += (((u32)gFarmRankingData.houseExtensions[slot] * 100) / 6);

    totalScore += (((u32)gFarmRankingData.grassTiles[slot] * 400) / 480);

    totalScore += (((u32)gFarmRankingData.happiness[slot] * 400) / MAX_HAPPINESS);

    farmRankingRawScore = (u32)totalScore;

    gFarmRankingData.scores[slot] = totalScore / 70.0f;

}
