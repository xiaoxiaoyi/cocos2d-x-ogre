/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2008 Renato Araujo Oliveira Filho <renatox@gmail.com>
Copyright (c) 2000-2012 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef __NoneGLWindow_H__
#define __NoneGLWindow_H__

#include "OgreRenderWindow.h"
#include "OgreNoneGLSupport.h"
#include "OgreNoneGLContext.h"

namespace Ogre {
    class _OgrePrivate NoneGLWindow : public RenderWindow
    {
	private:
        protected:
            bool mClosed;
            bool mVisible;
            bool mIsTopLevel;
            bool mIsExternal;
            bool mIsExternalGLControl;

            NoneGLSupport* mGLSupport;
            NoneGLContext* mContext;
			virtual void switchFullScreen(bool fullscreen);
			
			virtual void resize(uint width, uint height){}
			virtual void reposition(int x, int y){}
	public:
            NoneGLWindow(NoneGLSupport* glsupport);
            virtual ~NoneGLWindow();

//		Moved create to native source because it has native calls in it.
            void create(const String& name, unsigned int width, unsigned int height,
                        bool fullScreen, const NameValuePairList *miscParams);

			virtual void setFullscreen (bool fullscreen, uint width, uint height);
            void destroy(void);
            bool isClosed(void) const;
            bool isVisible(void) const;
            void setVisible(bool visible);
            void swapBuffers(bool waitForVSync);
            void copyContentsToMemory(const PixelBox &dst, FrameBuffer buffer);

            /**
               @remarks
               * Get custom attribute; the following attributes are valid:
               * WINDOW         The X NativeWindowType target for rendering.
               * GLCONTEXT      The Ogre GLContext used for rendering.
               * DISPLAY        EGLDisplay connection behind that context.
               * DISPLAYNAME    The name for the connected display.
               */
            virtual void getCustomAttribute(const String& name, void* pData);

            bool requiresTextureFlipping() const;
    };
}

#endif