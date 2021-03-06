#ifndef SLICERENDERER_HPP_
#define SLICERENDERER_HPP_

#include <FAST/Visualization/Plane.hpp>
#include <FAST/Visualization/ImageRenderer/ImageRenderer.hpp>
#include "FAST/Visualization/Renderer.hpp"
#include "FAST/Data/Image.hpp"

namespace fast {

class ImageSlicer;

class FAST_EXPORT  SliceRenderer : public ImageRenderer {
    FAST_OBJECT(SliceRenderer)
    public:
        uint addInputConnection(DataPort::pointer port) override;
        /**
         * Orthogonal slicing using the specified orthogonal plane.
         * @param port
         * @param orthogonalSlicePlane
         * @param sliceNr
         * @return port id of new port
         */
        uint addInputConnection(DataPort::pointer port, PlaneType orthogonalSlicePlane, int sliceNr = -1);
        /**
         * Arbitrary slicing using the supplied plane.
         * @param port
         * @param slicePlane
         * @return port id of new port
         */
        uint addInputConnection(DataPort::pointer port, Plane slicePlane);
        /**
         * Add new input connection using supplied slicer
         * @param port
         * @param slicer
         * @return port id of new port
         */
        uint addInputConnection(DataPort::pointer port, SharedPointer<ImageSlicer> slicer);
        void setOrthogonalSlicePlane(uint portID, PlaneType orthogonalSlicePlane, int sliceNr = -1);
        void setArbitrarySlicePlane(uint portID, Plane slicePlane);
    private:
        SliceRenderer();
        void execute() override;

        std::unordered_map<uint, SharedPointer<ImageSlicer>> mSlicers;
};

}




#endif /* SLICERENDERER_HPP_ */
