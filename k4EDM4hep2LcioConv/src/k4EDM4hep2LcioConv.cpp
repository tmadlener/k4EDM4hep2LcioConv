#include "k4EDM4hep2LcioConv/k4EDM4hep2LcioConv.h"
#include "edm4hep/Constants.h"
#include "EVENT/MCParticle.h"

namespace EDM4hep2LCIOConv {

  // The EventHeaderCollection should be of length 1
  void convEventHeader(const edm4hep::EventHeaderCollection* const header_coll, lcio::LCEventImpl* const lcio_event)
  {
    if (header_coll->size() != 1) {
      return;
    }

    const auto& header = header_coll->at(0);
    lcio_event->setEventNumber(header.getEventNumber());
    lcio_event->setRunNumber(header.getRunNumber());
    lcio_event->setTimeStamp(header.getTimeStamp());
    lcio_event->setWeight(header.getWeight());
  }

  // Check if a collection is already in the event by its name
  bool collectionExist(const std::string& collection_name, const lcio::LCEventImpl* lcio_event)
  {
    const auto* coll = lcio_event->getCollectionNames();
    return std::find(coll->begin(), coll->end(), collection_name) != coll->end();
  }

  std::unique_ptr<lcio::LCEventImpl> convEvent(const podio::Frame& edmEvent, const podio::Frame& metadata)
  {
    auto lcioEvent = std::make_unique<lcio::LCEventImpl>();
    auto objectMappings = CollectionsPairVectors {};

    const auto& collections = edmEvent.getAvailableCollections();
    for (const auto& name : collections) {
      const auto edmCollection = edmEvent.get(name);

      const auto& cellIDStr =
        metadata.getParameter<std::string>(podio::collMetadataParamName(name, edm4hep::CellIDEncoding));

      if (auto lcColl = convertCollection(edmCollection, name, objectMappings, cellIDStr)) {
        lcioEvent->addCollection(lcColl, name);
      }
      else {
        // Check whether we need to convert the EventHeader
        if (auto evtHeader = dynamic_cast<const edm4hep::EventHeaderCollection*>(edmCollection)) {
          convEventHeader(evtHeader, lcioEvent.get());
        }
      }
    }

    FillMissingCollections(objectMappings);

    return lcioEvent;
  }

} // namespace EDM4hep2LCIOConv
