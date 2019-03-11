#ifndef PandaProd_Producer_ProtonsFiller_h
#define PandaProd_Producer_ProtonsFiller_h

#include "FillerBase.h"

#include "DataFormats/Common/interface/View.h"
#include "DataFormats/CTPPSReco/interface/CTPPSLocalTrackLite.h"

class ProtonsFiller : public FillerBase {
 public:
  ProtonsFiller(std::string const&, edm::ParameterSet const&, edm::ConsumesCollector&);
  ~ProtonsFiller() {}

  void branchNames(panda::utils::BranchList& eventBranches, panda::utils::BranchList&) const override;
  void fill(panda::Event&, edm::Event const&, edm::EventSetup const&) override;

 protected:
  typedef edm::View<CTPPSLocalTrackLite> ProtonView;
  NamedToken<ProtonView> protonsToken_;
};

#endif
