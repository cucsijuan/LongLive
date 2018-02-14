// Fill out your copyright notice in the Description page of Project Settings.

#include "Opinion.h"

void UOpinion::SetOpinion(ERelationModifiers RelationModifier, uint32 amount, uint32 time)
{
	SOpinion temp;
	temp.Time = time;
	temp.OpinionMod = amount;

	switch (RelationModifier) {
	case ERelationModifiers::COMPETITION:
		temp.OpinionMod = -50;
		OpinionsArray.Add(temp);
		break;
	case ERelationModifiers::FAVOUR:
		temp.OpinionMod = 30;
		OpinionsArray.Add(temp);
		break;
	case ERelationModifiers::GIFT:
		temp.OpinionMod = 10;
		OpinionsArray.Add(temp);
		break;
	}
}



