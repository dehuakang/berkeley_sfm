/*
 * Copyright (c) 2015, The Regents of the University of California (Regents).
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *    3. Neither the name of the copyright holder nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS AS IS
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Please contact the author(s) of this library if you have any questions.
 * Authors: Erik Nelson            ( eanelson@eecs.berkeley.edu )
 *          David Fridovich-Keil   ( dfk@eecs.berkeley.edu )
 */

///////////////////////////////////////////////////////////////////////////////
//
// This class defines a camera model implemented using computations and
// parameters from the OpenCV camera model:
// http://docs.opencv.org/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html
//
///////////////////////////////////////////////////////////////////////////////

#ifndef BSFM_CAMERA_CAMERA_H
#define BSFM_CAMERA_CAMERA_H

#include "camera_extrinsics.h"
#include "camera_intrinsics.h"

namespace bsfm {

class Camera {
 public:

  // Constructor and destructor.
  Camera();
  ~Camera();

  // Constructor given extrinsics and intrinsics.
  Camera(CameraExtrinsics, CameraIntrinsics);

  // Set extrinsics.
  void SetExtrinsics(const CameraExtrinsics&);

  // Set instrinsics.
  void SetIntrinsics(const CameraIntrinsics&);

  // Extract mutable/immutable extrinsics/intrinsics.
  CameraExtrinsics &MutableExtrinsics();
  CameraIntrinsics &MutableIntrinsics();
  const CameraExtrinsics& Extrinsics() const;
  const CameraIntrinsics& Intrinsics() const;

  // Transform points from world to camera coordinates.
  void WorldToCamera(double, double, double,
                     double*, double*, double*) const;

  // Transform points from camera to world coordinates.
  void CameraToWorld(double, double, double,
                     double*, double*, double*) const;

  // Check if a point is in front of the camera.
  bool CameraToImage(double, double, double,
                     double*, double *) const;

  bool DirectionToImage(double, double,
                        double*, double*) const;

  void ImageToDirection(double, double,
                        double*, double*) const;

  // Warp a point into the image.
  void Distort(double, double,
               double*, double*) const;

  // Rectilinearize point.
  void Undistort(double, double,
                 double*, double*) const;

 private:
  CameraExtrinsics extrinsics_;
  CameraIntrinsics intrinsics_;
};  //\class Camera

}  //\bsfm
#endif
