#pragma once

#include <core/cube.h>
#include <core/solver.h>

#include <array>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "sticker.h"

namespace cubesolver {

namespace visualizer {

/**
 * Enum representation for the different states the application is in
 */
enum AppState {
  /* User currently selecting X-colored stickers */
  select_red,
  select_orange,
  select_blue,
  select_green,
  select_yellow,
  /* User has selected all stickers */
  all_selected,
  /* Application is currently computing a solution to the cube */
  solving,
  /* Application has output a solution */
  solved
};

/**
 * Overloaded increment operator to facilitate progression from an app state to
 * the next
 */
AppState& operator++(AppState& state);

/**
 * Visual GUI for input of a scrambled cube and ability to view a solution.
 */
class CubeSolverApp : public ci::app::App {
 public:
  CubeSolverApp();

  /**
   * Overloaded Cinder-specific methods
   */
  void setup() override;
  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  /**
   * Various dimensions for visual objects
   */
  const double kWindowWidth = 1600;
  const double kWindowHeight = 900;
  const double kStickerWidth = 100;

 private:
  /*
   * Array of Sticker objects (see Cube class for details on how Stickers are
   * stored)
   */
  std::array<std::array<Sticker, kNumCornersPerFace>, kNumFaces> stickers_;
  /* The current state the application is in */
  AppState current_state_;
  /* A count of the number of the current color the user has selected */
  size_t color_count_;

  Solver solver_;
  std::vector<Move> solution_;

  /**
   * Constructs a face of the Rubik's cube at the given location.
   *
   * @param face             The face to be drawn.
   * @param top_left_corner  The top left corner of the face to be drawn.
   */
  void CreateFace(const Face& face, const glm::vec2& top_left_corner);
  /** Clears all stickers and resets the application */
  void Clear();
  /** Solves the Rubik's cube given by the user */
  void Solve();
};

}  // namespace visualizer

}  // namespace cubesolver