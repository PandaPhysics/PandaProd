#include "../interface/ProtonsFiller.h"

#include "DataFormats/Common/interface/RefToPtr.h"

ProtonsFiller::ProtonsFiller(std::string const& _name, edm::ParameterSet const& _cfg, edm::ConsumesCollector& _coll) :
  FillerBase(_name, _cfg)
{
  //if (isRealData_)
  getToken_(protonsToken_, _cfg, _coll, "protons");
}

void
ProtonsFiller::branchNames(panda::utils::BranchList& _eventBranches, panda::utils::BranchList&) const
{
  //if (isRealData_)
  _eventBranches.emplace_back("protons");
}

void
ProtonsFiller::fill(panda::Event& _outEvent, edm::Event const& _inEvent, edm::EventSetup const& _setup)
{
  //if (!isRealData_)
  //return;

  auto& inProtons(getProduct_(_inEvent, protonsToken_));

  auto& outProtons(_outEvent.protons);

  for (auto& inProton : inProtons) {

    auto& outProton(outProtons.create_back());

    outProton.x = inProton.getX();
    outProton.xUnc = inProton.getXUnc();
    outProton.y = inProton.getY();
    outProton.yUnc = inProton.getYUnc();
    outProton.rpId = inProton.getRPId();

  }
}

DEFINE_TREEFILLER(ProtonsFiller);
