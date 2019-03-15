//
// Wire
// Copyright (C) 2019 Wire Swiss GmbH
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see http://www.gnu.org/licenses/.
//

import Foundation

class SoundPreviewPlayer {
    
    fileprivate var mediaManager: AVSMediaManager
    fileprivate var stopTimer: Timer?
    
    init(mediaManager: AVSMediaManager) {
        self.mediaManager = mediaManager
    }
    
    func playPreview(_ sound: String, limit: TimeInterval = 3) {
        stopTimer?.fire()
        mediaManager.playSound(sound)
        
        stopTimer = Timer.scheduledTimer(withTimeInterval: limit, repeats: false) { [weak self] _ in
            self?.mediaManager.stopSound(sound)
            self?.stopTimer = nil
        }
    }
    
}
