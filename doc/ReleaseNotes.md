# v00-05

* 2023-07-10 tmadlener ([PR#23](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/23))
  - Remove the explicit `clang-format-check` workflow as it is also covered by the `pre-commit` workflow.

* 2023-07-10 Frank Gaede ([PR#20](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/20))
  - Add the possibility to convert only a subset of collections and events.
  - Fix minor bug in TrackState conversion (covMatrix[15])
  - Write `AllCaloHitContributionsCombined` only if needed, i.e. `SimCalorimeterHits` are present in the events in lcio2edm4hep

* 2023-06-13 Finn Johannsen ([PR#11](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/11))
  - Add LCIO to EDM4hep conversion functionality with a similar interface as the one that is already present for the other direction.

* 2023-06-07 Thomas Madlener ([PR#16](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/16))
  - Match the renaming of `subdetectorHitNumbers` in EDM4hep (cf. [key4hep/EDM4hep#188](https://github.com/key4hep/EDM4hep/pull/188))
  - Introduce some guards for the `TPCHit` -> `RawTimeSeries` change in EDM4hep (cf. [key4hep/EDM4hep#179](https://github.com/key4hep/EDM4hep/pull/179))

* 2023-04-19 Leonhard Reichenbach ([PR#13](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/13))
  - Add support for EventHeader conversion

# v00-04

* 2023-03-02 jmcarcell ([PR#8](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/8))
  - Rename TPCHit -> RawTimeSeries

* 2023-02-22 Thomas Madlener ([PR#9](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/9))
  - Fix the pre-commit workflow and update it to run using a newer LCG release

* 2023-02-22 Finn Johannsen ([PR#4](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/4))
  - Fix the setting of the Track Type in the Tracks Collection in LCIO. It is now set bit wise as required by LCIO

# v00-03

* 2022-11-30 Andre Sailer ([PR#7](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/7))
  - SimCaloHitContribution Conversion: fix an issue when the MCParticles were not converted before the SimCalorimeterHits, which is happening now that the map of collections is sorted in some way according to c++ implementation. Belongs to key4hep/k4MarlinWrapper#99 Fixes key4hep/k4MarlinWrapper#98

* 2022-10-06 Andre Sailer ([PR#6](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/6))
  - CI: add pre-commit workflow with clang-format and whitespace checker

* 2022-10-06 Andre Sailer ([PR#5](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/5))
  - CI: add test for compiling this project

# v00-02-01

* 2022-06-16 Thomas Madlener ([PR#3](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/3))
  - Update cov matrix type after key4hep/EDM4hep#138

# v00-02

* 2022-05-30 Valentin Volkl ([PR#2](https://github.com/key4hep/k4EDM4hep2LcioConv/pull/2))
  - HitContributions were removed from Clusters in https://github.com/key4hep/EDM4hep/pull/140

# v00-01

# v00-00

* Add versioning
