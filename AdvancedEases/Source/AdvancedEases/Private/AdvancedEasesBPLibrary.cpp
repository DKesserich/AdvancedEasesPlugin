/*
MIT License

Copyright (c) 2023 David Lejeune

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "AdvancedEasesBPLibrary.h"
#include "AdvancedEases.h"

float UAdvancedEasesBPLibrary::AdvancedEase_Float(EAdvancedEases EaseType, float Delta, float Start, float End)
{
    float easeDelta = End - Start;

    switch (EaseType)
    {
    case EAdvancedEases::AE_INBACK:
    {
        return easeDelta * EaseInBack(Delta) + Start;
    }
    case EAdvancedEases::AE_OUTBACK:
    {
        return easeDelta * EaseOutBack(Delta) + Start;
    }
    case EAdvancedEases::AE_INOUTBACK:
    {
        return easeDelta * EaseInOutBack(Delta) + Start;
    }
    case EAdvancedEases::AE_INBOUNCE:
    {
        return easeDelta * EaseInBounce(Delta) + Start;
    }
    case EAdvancedEases::AE_OUTBOUNCE:
    {
        return easeDelta * EaseOutBounce(Delta) + Start;
    }
    case EAdvancedEases::AE_INOUTBOUNCE:
    {
        return easeDelta * EaseInOutBounce(Delta) + Start;
    }
    case EAdvancedEases::AE_INELASTIC:
    {
        return easeDelta * EaseInElastic(Delta) + Start;
    }
    case EAdvancedEases::AE_OUTELASTIC:
    {
        return easeDelta * EaseOutElastic(Delta) + Start;
    }
    case EAdvancedEases::AE_INOUTELASTIC:
    {
        return easeDelta * EaseInOutElastic(Delta) + Start;
    }
    default:
    {
        return easeDelta * Delta + Start;
    }
    }
}

FVector UAdvancedEasesBPLibrary::AdvancedEase_Vector(EAdvancedEases EaseType, const FVector& Start, const FVector& End, float Delta)
{
    FVector easeDelta = End - Start;

    return (easeDelta * AdvancedEase_Float(EaseType, Delta)) + Start;
}

float UAdvancedEasesBPLibrary::EaseInBack(float Delta)
{
    const float c1 = 1.70158;
    const float c3 = c1 + 1;

    return c3 * Delta * Delta * Delta - c1 * Delta * Delta;
}

float UAdvancedEasesBPLibrary::EaseOutBack(float Delta)
{
    const float c1 = 1.70158;
    const float c3 = c1 + 1;

    return 1 + c3 * pow(Delta - 1, 3) + c1 * pow(Delta - 1, 2);
}

float UAdvancedEasesBPLibrary::EaseInOutBack(float Delta)
{
    const float c1 = 1.70158;
    const float c2 = c1 * 1.525;

    if (Delta < 0.5)
    {
        return (pow(2 * Delta, 2) * ((c2 + 1) * 2 * Delta - c2)) / 2;
    }
    else
    {
        return (pow(2 * Delta - 2, 2) * ((c2 + 1) * (Delta * 2 - 2) + c2) + 2) / 2;
    }
}

float UAdvancedEasesBPLibrary::EaseInBounce(float Delta)
{
    return 1 - EaseOutBounce(1 - Delta);
}

float UAdvancedEasesBPLibrary::EaseOutBounce(float Delta)
{
    const float n1 = 7.5625;
    const float d1 = 2.75;

    if (Delta < (1 / d1))
    {
        return n1 * Delta * Delta;
    }
    else if (Delta < (2 / d1))
    {
        return n1 * (Delta -= 1.5 / d1) * Delta + 0.75;
    }
    else if (Delta < (2.5 / d1))
    {
        return n1 * (Delta -= 2.25 / d1) * Delta + 0.9375;
    }
    else
    {
        return n1 * (Delta -= 2.625 / d1) * Delta + 0.984375;
    }
}

float UAdvancedEasesBPLibrary::EaseInOutBounce(float Delta)
{
    if (Delta < 0.5)
    {
        return ((1 - EaseOutBounce(1 - 2 * Delta)) / 2);
    }
    else
    {
        return ((1 + EaseOutBounce(2 * Delta - 1)) / 2);
    }
}

float UAdvancedEasesBPLibrary::EaseInElastic(float Delta)
{
    const float c4 = (2 * PI) / 3;

    if (Delta > 0 && Delta < 1)
    {
        return -pow(2, 10 * Delta - 10) * sin((Delta * 10 - 10.75) * c4);
    }
    else
    {
        return Delta;
    }
}

float UAdvancedEasesBPLibrary::EaseOutElastic(float Delta)
{
    const float c4 = (2 * PI) / 3;

    if (Delta > 0 && Delta < 1)
    {
        return pow(2, -10 * Delta) * sin((Delta * 10 - 0.75) * c4) + 1;
    }
    else
    {
        return Delta;
    }
}

float UAdvancedEasesBPLibrary::EaseInOutElastic(float Delta)
{
    const float c5 = (2 * PI) / 4.5;

    if (0 < Delta && Delta < 1)
    {
        if (Delta < 0.5)
        {
            return -(pow(2, 20 * Delta - 10) * sin((20 * Delta - 11.125) * c5)) / 2;
        }
        else
        {
            return (pow(2, -20 * Delta + 10) * sin((20 * Delta - 11.125) * c5)) / 2 + 1;
        }
    }
    else
    {
        return Delta;
    }
}


