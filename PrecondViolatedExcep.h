#ifndef LAB5_PRECONDVIOLATEDEXCEP_H
#define LAB5_PRECONDVIOLATEDEXCEP_H
#include <stdexcept>
#include <string>

/** @class PrecondViolatedExcep PrecondViolatedExcep.h "PrecondViolatedExcep.h"
 *
 *  Specification for an object thrown on violation of precondition. */
class PrecondViolatedExcep : public std::logic_error {
public:
    explicit PrecondViolatedExcep(const std::string& message = "");

    virtual ~PrecondViolatedExcep() noexcept = default;
};
#endif //LAB5_PRECONDVIOLATEDEXCEP_H
