/*
 * Copyright (c) 2009 Tias Guns
 * Copyright (c) 2009 Soren Hauberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _calibrator_hh
#define _calibrator_hh

// Abstract base class for calculating new calibration parameters
class Calibrator
{
public:
    /* Constructor for a specific calibrator
     *
     * The constructor will throw an exception,
     * if the touchscreen is not of the type it supports
     */
    Calibrator(const char* const device_name, const XYinfo& axys, const bool verbose);
    ~Calibrator() {}

    // get the number of clicks already registered
    int get_numclicks();
    // add a click with the given coordinates
    bool add_click(int x, int y);
    // calculate and apply the calibration
    bool finish(int width, int height);

protected:
    // overloaded function that applies the new calibration
    virtual bool finish_data(const XYinfo new_axys, int swap_xy) =0;

    // name of the device (driver)
    const char* const device_name;
    // original axys values
    XYinfo old_axys;
    // be verbose or not
    bool verbose;
    // nr of clicks registered
    int num_clicks;
    // click coordinates
    int clicked_x[4], clicked_y[4];
};

#endif
