#ifndef _FIXALLPOINTS_HPP_EKAKA
#define _FIXALLPOINTS_HPP_EKAKA

#include <set>

#include "abstract_constraint.hpp"
#include "../partition_stack.hpp"
#include "../partition_refinement.hpp"
#include <iostream>

// This constraint is useless (it just fixes all points)
// it represents the identity group, and is useful because
// the identity group has a stupid stabilizer chain.
class FixAllPoints : public AbstractConstraint
{
public:

    virtual std::string name() const
    { return "FixAllPoints"; }


    FixAllPoints(PartitionStack* ps)
    : AbstractConstraint(ps)
    {
    }

    SplitState init()
    {
        debug_out(1, "FixAllPoints", "init");
        vec1<int> points;
        for(int i = 1; i <= ps->domainSize(); ++i)
            points.push_back(i);
        return filterPartitionStackByFunction(ps, ContainerToFunction(&points));
    }

    virtual bool verifySolution(const Permutation& p)
    {
        for(int i = 1; i <= p.size(); ++i)
            if(p[i] != i)
                return false;
        return true;
    }
};

#endif
