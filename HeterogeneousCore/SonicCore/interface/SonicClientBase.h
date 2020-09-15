#ifndef HeterogeneousCore_SonicCore_SonicClientBase
#define HeterogeneousCore_SonicCore_SonicClientBase

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"
#include "FWCore/Concurrency/interface/WaitingTaskWithArenaHolder.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "HeterogeneousCore/SonicCore/interface/SonicDispatcher.h"
#include "HeterogeneousCore/SonicCore/interface/SonicDispatcherPseudoAsync.h"

#include <string>
#include <chrono>
#include <exception>
#include <memory>

enum class SonicMode { Sync = 1, Async = 2, PseudoAsync = 3 };

class SonicClientBase {
public:
  //constructor
  SonicClientBase(const edm::ParameterSet& params);

  //destructor
  virtual ~SonicClientBase() = default;

  void setDebugName(const std::string& debugName);
  const std::string& debugName() const { return debugName_; }
  const std::string& clientName() const { return clientName_; }
  SonicMode mode() const { return mode_; }

  //main operation
  virtual void dispatch(edm::WaitingTaskWithArenaHolder holder) { dispatcher_->dispatch(std::move(holder)); }

  //helper: does nothing by default
  virtual void reset() {}

  //provide base params
  static void fillBasePSetDescription(edm::ParameterSetDescription& desc, bool allowRetry = true);

protected:
  virtual void evaluate() = 0;

  void start(edm::WaitingTaskWithArenaHolder holder);

  void finish(bool success, std::exception_ptr eptr = std::exception_ptr{});

  //members
  SonicMode mode_;
  std::unique_ptr<SonicDispatcher> dispatcher_;
  unsigned allowedTries_, tries_;
  edm::WaitingTaskWithArenaHolder holder_;

  //for logging/debugging
  std::string clientName_, debugName_, fullDebugName_;
  std::chrono::time_point<std::chrono::high_resolution_clock> t0_;

  friend class SonicDispatcher;
  friend class SonicDispatcherPseudoAsync;
};

#endif
