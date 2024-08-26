#pragma once

class FortranWrapper {
public:
    FortranWrapper();
    void computePositions(float dt, int steps);
    ~FortranWrapper();
};
