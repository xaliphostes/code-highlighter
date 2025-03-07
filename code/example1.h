#include <task>

class Switch : public Task {
  public:
    // Type definitions for selector functions
    using SelectorFunction = std::function<std::string(const ArgumentPack &)>;

    void execute(const ArgumentPack &args = {});

  private:
    SelectorFunction m_selector;
};
