////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     MakeTrainer.h (common)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ForestTrainerArguments.h"
#include "MultiEpochIncrementalTrainerArguments.h"
#include "SGDIncrementalTrainerArguments.h"
#include "TrainerArguments.h"

// predictors
#include "LinearPredictor.h"

// trainers
#include "IIncrementalTrainer.h"

// stl
#include <memory>

namespace ell
{
namespace common
{
    /// <summary> Makes a stochastic gradient descent incremental trainer. </summary>
    ///
    /// <param name="dim"> The dimension. </param>
    /// <param name="lossArguments"> loss arguments. </param>
    /// <param name="trainerArguments"> trainer arguments. </param>
    ///
    /// <returns> A unique_ptr to a stochastic gradient descent trainer. </returns>
    std::unique_ptr<trainers::IIncrementalTrainer<predictors::LinearPredictor>> MakeSGDIncrementalTrainer(uint64_t dim, const LossArguments& lossArguments, const SGDIncrementalTrainerArguments& trainerArguments);

    /// <summary> Makes a forest trainer. </summary>
    ///
    /// <param name="lossArguments"> loss arguments. </param>
    /// <param name="trainerArguments"> trainer arguments. </param>
    ///
    /// <returns> A unique_ptr to a forest trainer. </returns>
    std::unique_ptr<trainers::IIncrementalTrainer<predictors::SimpleForestPredictor>> MakeForestTrainer(const LossArguments& lossArguments, const ForestTrainerArguments& trainerArguments);
}
}
